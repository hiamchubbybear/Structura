#include <iostream>
#include <filesystem>
#include <map>
// @author : Chessy
// @date : 17/10/2024
// @def  filesystem
namespace fs = std::filesystem;
static std::filesystem::perms read_perm = std::filesystem::perms::owner_read;
static std::filesystem::perms all_perm = std::filesystem::perms::all;
static std::filesystem::perms write_perm = std::filesystem::perms::owner_write;
class Structura
{
    //  Check wether path is exists ?
    //  return:
    //   true : directory is existed , is directory && is empty.
    //   false : else.
    //  @note : need to be optimize
    // @notice : alg not optimized
public:
    bool isValidPath(const fs::path &dirpath)
    {
        return !fs::exists(dirpath) && fs::is_directory(dirpath) && !fs::is_empty(dirpath);
    }
public:
    fs::path pathToCreate(const std::string file_type)
    {
        std::map<std::string, std::string> fileTypeToDirectory = {
            // Documents
            {".doc", "Documents"},
            {".docx", "Documents"},
            {".pdf", "Documents"},
            {".txt", "TextFiles"},
            {".rtf", "TextFiles"},
            {".odt", "Documents"},
            {".tex", "Documents"},
            {".md", "Documents"},
            {".wpd", "Documents"},
            // Presentations
            {".ppt", "Presentations"},
            {".pptx", "Presentations"},
            {".key", "Presentations"},
            {".odp", "Presentations"},
            // Sheets
            {".xls", "Spreadsheets"},
            {".xlsx", "Spreadsheets"},
            {".csv", "DataFiles"},
            {".ods", "Spreadsheets"},
            // Images
            {".jpg", "Images"},
            {".jpeg", "Images"},
            {".png", "Images"},
            {".gif", "Images"},
            {".bmp", "Images"},
            {".tiff", "Images"},
            {".svg", "Images"},
            {".webp", "Images"},
            // Videos
            {".mp4", "Videos"},
            {".avi", "Videos"},
            {".mkv", "Videos"},
            {".mov", "Videos"},
            {".wmv", "Videos"},
            {".flv", "Videos"},
            {".webm", "Videos"},
            {".mpeg", "Videos"},
            // Audio
            {".mp3", "Audio"},
            {".wav", "Audio"},
            {".flac", "Audio"},
            {".aac", "Audio"},
            {".ogg", "Audio"},
            {".m4a", "Audio"},
            {".wma", "Audio"},
            // Compressed
            {".zip", "Compressed"},
            {".rar", "Compressed"},
            {".7z", "Compressed"},
            {".tar", "Compressed"},
            {".gz", "Compressed"},
            {".bz2", "Compressed"},
            {".xz", "Compressed"},
            // Executables File
            {".exe", "Executables"},
            {".dll", "Executables"},
            {".sys", "SystemFiles"},
            {".bat", "Scripts"},
            {".sh", "Scripts"},
            {".iso", "DiskImages"},
            {".img", "DiskImages"},
            // Developfile
            {".cpp", "Cpp"},
            {".h", "C"},
            {".out", "Executables"},
            {"", "Executables"},
            {".hpp", "CppHeader"},
            {".py", "Python"},
            {".java", "Java"},
            {".js", "Javascript"},
            {".html", "HyperTextMarkupLanguage"},
            {".css", "StyleSheetLanguage"},
            {".php", "PHP"},
            {".rb", "Ruby"},
            {".swift", "Swift"},
            {".go", "Golang"},
            {".rs", "Rust"},
            {".ts", "Typescripts"},
            {".db", "Database"},
            {".sql", "Database"},
            {".sqlite", "Database"},
            {".mdb", "Database"},
            {".accdb", "Database"},
            {".ics", "Calendar"},
            {".xml", "Data"},
            {".json", "Data"},
            {".yml", "Data"},
            {".yaml", "Data"},
            {".log", "Log"}};
        // Loop to map .type with Subdirectory name
        for (const auto &[extension, directory] : fileTypeToDirectory)
        {
            if (file_type == extension)
                return directory;
        }
        return "Undefine";
    }

public:
    void createSubdir(const fs::path &file)
    {
        std::string file_type = file.extension().string();
        std::string file_path = file;
        try
        {
            if (!fs::exists(pathToCreate(file)))
                if (fs::create_directories(file_path.append("/").append(pathToCreate(file_type))))
                    std::cout << "Create subdir success";
                else
                    std::cout << "Failed to create subdirectory";
            else
                std::cout << "Subdirectory already exists";
        }
        catch (const fs::filesystem_error err)
        {
            std::cerr << err.what() << '\n';
        }
    }
    // List all directory and subdirectory
    // If do not have permission -> skip
public:
    void listPath(const fs::path &dirpath)
    {
        std::string rootPath = dirpath;
        try
        {
            for (const auto &entry :
                 fs::directory_iterator(dirpath))
            {
                std::cout << "File :" << entry.path() << "\n";
                // Test create subdir
                createSubdir(rootPath);
                if (fs::is_directory(entry.status()))
                {
                    // Declared permission -> permiss
                    fs::perms permiss = fs::status(entry.path()).permissions();
                    // Check if have permission to read? Yes  -> std::cout
                    if ((permiss & read_perm) != fs::perms::none)
                    {
                        std::cout << "---------------------------\nSubdirectory :" << entry.path().extension().string() << "\n";
                        listPath(entry.path());
                    }
                    else
                    {
                        // No -> std::notice & skip it
                        std::cout << "You don't have permission to read -- SKIP ->";
                        continue;
                    }
                }
            }
        }
        catch (const fs::filesystem_error &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
};
int main()
{
    Structura p;
    // Input path
    std::string orpath = "/";
    std::cout << "Path: ";
    std::cin >> orpath;
    fs::path dirpath = orpath;
    // Executed
    if (p.isValidPath(dirpath))
    {
        std::cout << "Path not found ";
    }
    else
    {
        std::cout << "Path found." << std::endl;
        p.listPath(dirpath);
    }

    return 0;
}
