#include <iostream>
#include <filesystem>
#include <map>
#include <vector>
// @author : Chessy
// @date : 17/10/2024
// @def  filesystem
namespace fs = std::filesystem;
// @def movefile
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
    // @note Can not map extension  with Directory Name
public:
    std::string mapName(const fs::path &file)
    {
        if (!file.has_extension())
            return "Undefine";

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
            {".epub", "Documents"},
            {".xps", "Documents"},
            {".wps", "Documents"},
            {".dot", "Documents"},
            {".dotx", "Documents"},
            {".xml", "Data"},      // XML files
            {".csv", "DataFiles"}, // Comma Separated Values
            {".tsv", "DataFiles"}, // Tab Separated Values
            {".log", "Log"},       // Log files
            {".bib", "BibTeX"},    // Bibliography files

            // Presentations
            {".ppt", "Presentations"},
            {".pptx", "Presentations"},
            {".key", "Presentations"},
            {".odp", "Presentations"},
            {".pps", "Presentations"},
            {".ppsx", "Presentations"},
            {".sxi", "Presentations"}, // StarOffice Impress

            // Sheets
            {".xls", "Spreadsheets"},
            {".xlsx", "Spreadsheets"},
            {".ods", "Spreadsheets"},
            {".xlr", "Spreadsheets"},
            {".numbers", "Spreadsheets"},
            {".xlsm", "Spreadsheets"},
            {".csv", "DataFiles"},    // Comma-separated values
            {".prn", "Spreadsheets"}, // Print file format

            // Images
            {".jpg", "Images"},
            {".jpeg", "Images"},
            {".png", "Images"},
            {".gif", "Images"},
            {".bmp", "Images"},
            {".tiff", "Images"},
            {".svg", "Images"},
            {".webp", "Images"},
            {".heif", "Images"},
            {".heic", "Images"},
            {".raw", "Images"},
            {".cr2", "Images"},
            {".nef", "Images"},
            {".orf", "Images"},
            {".dng", "Images"},
            {".psd", "Images"}, // Photoshop Document

            // Videos
            {".mp4", "Videos"},
            {".avi", "Videos"},
            {".mkv", "Videos"},
            {".mov", "Videos"},
            {".wmv", "Videos"},
            {".flv", "Videos"},
            {".webm", "Videos"},
            {".mpeg", "Videos"},
            {".3gp", "Videos"},
            {".vob", "Videos"},
            {".mts", "Videos"},
            {".m4v", "Videos"},
            {".f4v", "Videos"}, // Flash MP4 Video
            {".rm", "Videos"},  // RealMedia

            // Audio
            {".mp3", "Audio"},
            {".wav", "Audio"},
            {".flac", "Audio"},
            {".aac", "Audio"},
            {".ogg", "Audio"},
            {".m4a", "Audio"},
            {".wma", "Audio"},
            {".m4b", "Audio"},
            {".aiff", "Audio"},
            {".opus", "Audio"},
            {".caf", "Audio"},
            {".aif", "Audio"},
            {".midi", "Audio"},
            {".xm", "Audio"},  // Extended Module
            {".mod", "Audio"}, // Module files

            // Compressed
            {".zip", "Compressed"},
            {".rar", "Compressed"},
            {".7z", "Compressed"},
            {".tar", "Compressed"},
            {".gz", "Compressed"},
            {".bz2", "Compressed"},
            {".xz", "Compressed"},
            {".tar.gz", "Compressed"},
            {".tar.bz2", "Compressed"},
            {".zipx", "Compressed"},
            {".cab", "Compressed"},
            {".ace", "Compressed"},
            {".apk", "Compressed"},
            {".lz", "Compressed"},
            {".z", "Compressed"}, // Unix compress

            // Executables
            {".exe", "Executables"},
            {".dll", "Executables"},
            {".sys", "SystemFiles"},
            {".bat", "Scripts"},
            {".sh", "Scripts"},
            {".iso", "DiskImages"},
            {".img", "DiskImages"},
            {".jar", "Java Executables"},
            {".app", "Mac Applications"},
            {".com", "Executables"},
            {".msi", "Executables"},
            {".run", "Scripts"},
            {".bin", "Executables"}, // Binary executable

            // Development Files
            {".c", "C"},
            {".cc", "Cpp"},
            {".cxx", "Cpp"},
            {".c++", "Cpp"},
            {".hh", "CppHeader"},
            {".hxx", "CppHeader"},
            {".h++", "CppHeader"},
            {".inl", "CppInline"},
            {".ipp", "CppInline"},
            {".tcc", "CppTemplates"},
            {".tpp", "CppTemplates"},

            // C#
            {".cs", "CSharp"},
            {".csx", "CSharpScript"},
            {".csproj", "CSharpProject"},

            // Java
            {".java", "Java"},
            {".class", "JavaClass"},
            {".jar", "JavaArchive"},
            {".war", "JavaWebArchive"},
            {".ear", "JavaEnterpriseArchive"},
            {".jsp", "JavaServerPages"},
            {".jspx", "JavaServerPages"},

            // Python
            {".py", "Python"},
            {".pyw", "PythonWindows"},
            {".pyx", "Cython"},
            {".pxd", "CythonDefinition"},
            {".pxi", "CythonInclude"},
            {".pyc", "PythonCompiled"},
            {".pyo", "PythonOptimized"},
            {".pyd", "PythonDLL"},

            // JavaScript and TypeScript
            {".js", "JavaScript"},
            {".mjs", "JavaScriptModule"},
            {".cjs", "CommonJS"},
            {".ts", "TypeScript"},
            {".tsx", "TypeScriptReact"},
            {".jsx", "ReactJSX"},

            // PHP
            {".php", "PHP"},
            {".phtml", "PHPTemplate"},
            {".php4", "PHP4"},
            {".php5", "PHP5"},
            {".phps", "PHPSource"},
            {".phar", "PHPArchive"},

            // Ruby
            {".rb", "Ruby"},
            {".rbw", "RubyWindows"},
            {".rake", "RubyRake"},
            {".gemspec", "RubyGemSpec"},

            // Go
            {".go", "Go"},
            {".mod", "GoModule"},
            {".sum", "GoSum"},

            // Rust
            {".rs", "Rust"},
            {".rlib", "RustLib"},

            // Swift
            {".swift", "Swift"},
            {".swiftmodule", "SwiftModule"},

            // Kotlin
            {".kt", "Kotlin"},
            {".kts", "KotlinScript"},
            {".ktm", "KotlinModule"},

            // Scala
            {".scala", "Scala"},
            {".sc", "ScalaScript"},

            // Groovy
            {".groovy", "Groovy"},
            {".gvy", "Groovy"},
            {".gy", "Groovy"},
            {".gsh", "GroovyShell"},

            // Dart
            {".dart", "Dart"},

            // Lua
            {".lua", "Lua"},
            {".luac", "LuaCompiled"},

            // Perl
            {".pl", "Perl"},
            {".pm", "PerlModule"},
            {".t", "PerlTest"},

            // Haskell
            {".hs", "Haskell"},
            {".lhs", "LiterateHaskell"},

            // Erlang and Elixir
            {".erl", "Erlang"},
            {".hrl", "ErlangHeader"},
            {".ex", "Elixir"},
            {".exs", "ElixirScript"},

            // Clojure
            {".clj", "Clojure"},
            {".cljs", "ClojureScript"},
            {".cljc", "ClojureCommon"},

            // F#
            {".fs", "FSharp"},
            {".fsi", "FSharpSignature"},
            {".fsx", "FSharpScript"},

            // OCaml
            {".ml", "OCaml"},
            {".mli", "OCamlInterface"},

            // R
            {".r", "R"},
            {".rdata", "RData"},
            {".rds", "RSerializedData"},

            // Julia
            {".jl", "Julia"},

            // VB.NET
            {".vb", "VisualBasic"},
            {".vbproj", "VisualBasicProject"},

            // Assembly
            {".asm", "Assembly"},
            {".s", "AssemblyATT"},

            // FORTRAN
            {".f", "Fortran"},
            {".for", "Fortran"},
            {".f90", "Fortran90"},
            {".f95", "Fortran95"},

            // COBOL
            {".cob", "COBOL"},
            {".cbl", "COBOL"},

            // Lisp dialects
            {".lisp", "CommonLisp"},
            {".cl", "CommonLisp"},
            {".el", "EmacsLisp"},

            // Prolog
            {".pl", "Prolog"},
            {".pro", "Prolog"},

            // D
            {".d", "D"},
            {".di", "DInterface"},

            // Nim
            {".nim", "Nim"},
            {".nims", "NimScript"},

            // Crystal
            {".cr", "Crystal"},

            // PowerShell
            {".ps1", "PowerShell"},
            {".psm1", "PowerShellModule"},
            {".psd1", "PowerShellData"},

            // Bash and Shell scripts
            {".sh", "ShellScript"},
            {".bash", "BashScript"},
            {".zsh", "ZshScript"},
            {".fish", "FishScript"},

            // Objective-C
            {".m", "ObjectiveC"},
            {".mm", "ObjectiveCPP"},

            // Markdown and documentation
            {".md", "Markdown"},
            {".markdown", "Markdown"},
            {".rst", "ReStructuredText"},
            {".adoc", "AsciiDoc"},

            // Web development
            {".html", "HTML"},
            {".htm", "HTML"},
            {".xhtml", "XHTML"},
            {".css", "CSS"},
            {".sass", "Sass"},
            {".scss", "SCSS"},
            {".less", "Less"},
            {".styl", "Stylus"},
            {".svg", "SVG"},

            // Configuration and data formats
            {".json", "JSON"},
            {".yaml", "YAML"},
            {".yml", "YAML"},
            {".toml", "TOML"},
            {".ini", "INI"},
            {".cfg", "Config"},
            {".conf", "Config"},
            {".xml", "XML"},
            {".dtd", "DTD"},
            {".xsd", "XSD"},

            // Build and package management
            {".gradle", "Gradle"},
            {".sbt", "SBT"},
            {".maven", "Maven"},
            {".pom", "MavenPOM"},
            {".ant", "Ant"},
            {".cmake", "CMake"},
            {".make", "Makefile"},
            {".dockerfile", "Dockerfile"},
            {".vagrantfile", "Vagrantfile"},
            {".gemfile", "Gemfile"},
            {".podfile", "Podfile"},
            {".npmrc", "NPMConfig"},
            {".yarnrc", "YarnConfig"},
            {".editorconfig", "EditorConfig"},
            {".gitignore", "GitIgnore"},
            {".dockerignore", "DockerIgnore"},

            // Database
            {".sql", "SQL"},
            {".sqlite", "SQLite"},
            {".mongodb", "MongoDB"},
            {".cql", "Cassandra"},

            // Game development
            {".unity", "Unity"},
            {".unitypackage", "UnityPackage"},
            {".prefab", "UnityPrefab"},
            {".mat", "UnityMaterial"},
            {".fbx", "FBX"},
            {".blend", "Blender"},
            {".gltf", "glTF"},
            {".glb", "GLB"},

            // Machine Learning and Data Science
            {".ipynb", "JupyterNotebook"},
            {".pkl", "PickleFile"},
            {".h5", "HDF5"},
            {".onnx", "ONNX"},
            {".pb", "ProtocolBuffer"},
            {".mlmodel", "CoreMLModel"},

            // Configuration and Logs
            {".conf", "Configuration"},
            {".ini", "Configuration"},
            {".cfg", "Configuration"},
            {".env", "Configuration"},
            {".bak", "Backup"},

            // Web Files
            {".svg", "ScalableVectorGraphics"},
            {".woff", "WebFonts"},
            {".woff2", "WebFonts"},
            {".ico", "Icons"},
            {".jsonld", "Data"},
            {".rss", "Data"},
            {".atom", "Data"},
            {".css.map", "StyleSheetLanguage"}, // CSS source maps

            // Other
            {".torrent", "TorrentFiles"},
            {".dmg", "DiskImages"},
            {".vmdk", "DiskImages"},
            {".bin", "DiskImages"},
            {".md5", "Checksum"},
            {".sha1", "Checksum"},
            {".sha256", "Checksum"},
            {".pfx", "CertificateFiles"}, // Personal Information Exchange
            {".cer", "CertificateFiles"}, // Certificate files
            {".crt", "CertificateFiles"}, // Certificate files
            {".pem", "CertificateFiles"}, // Privacy Enhanced Mail

            // New additions
            {".ai", "VectorGraphics"},        // Adobe Illustrator
            {".eps", "VectorGraphics"},       // Encapsulated PostScript
            {".indd", "DesktopPublishing"},   // Adobe InDesign
            {".psd", "ImageEditing"},         // Adobe Photoshop
            {".xd", "DesignPrototyping"},     // Adobe XD
            {".sketch", "DesignPrototyping"}, // Sketch App
            {".fig", "DesignPrototyping"},    // Figma
            {".afdesign", "VectorGraphics"},  // Affinity Designer
            {".afphoto", "ImageEditing"},     // Affinity Photo
            {".blend", "3DModeling"},         // Blender
            {".max", "3DModeling"},           // 3ds Max
            {".ma", "3DModeling"},            // Maya ASCII
            {".mb", "3DModeling"},            // Maya Binary
            {".c4d", "3DModeling"},           // Cinema 4D
            {".fbx", "3DModeling"},           // Filmbox
            {".obj", "3DModeling"},           // Wavefront 3D Object File
            {".stl", "3DPrinting"},           // Stereolithography file
            {".gcode", "3DPrinting"},         // G-code file for 3D printing
            {".dwg", "CAD"},                  // AutoCAD Drawing
            {".dxf", "CAD"},                  // AutoCAD DXF
            {".rvt", "BIM"},                  // Revit Project
            {".rfa", "BIM"},                  // Revit Family
            {".ifc", "BIM"},                  // Industry Foundation Classes
            {".skp", "3DModeling"},           // SketchUp
            {".lyx", "Documents"},            // LyX Document
            {".bib", "Bibliography"},         // BibTeX Bibliography
            {".ipynb", "Notebooks"},          // Jupyter Notebook
            {".nb", "Notebooks"},             // Mathematica Notebook
            {".r", "Statistics"},             // R script
            {".sas", "Statistics"},           // SAS program
            {".spss", "Statistics"},          // SPSS file
            {".stata", "Statistics"},         // Stata file
            {".mat", "ScientificComputing"},  // MATLAB file
            {".nc", "ScientificData"},        // NetCDF file
            {".hdf5", "ScientificData"},      // Hierarchical Data Format
            {".fit", "FitnessData"},          // Flexible and Interoperable Data Transfer
            {".gpx", "GPSData"},              // GPS Exchange Format
            {".kml", "GeographicData"},       // Keyhole Markup Language
            {".shp", "GeographicData"},       // Shapefile
            {".mxd", "GeographicData"},       // ArcGIS Map Document
            {".qgz", "GeographicData"},       // QGIS Project
            {".osm", "GeographicData"},       // OpenStreetMap data
            {".ttf", "Fonts"},                // TrueType Font
            {".otf", "Fonts"},                // OpenType Font
            {".fnt", "Fonts"},                // Windows Font File
            {".fon", "Fonts"},                // Generic Font File
            {".mpp", "ProjectManagement"},    // Microsoft Project
            {".gan", "ProjectManagement"},    // GanttProject
            {".vsd", "Diagrams"},             // Visio Drawing
            {".vsdx", "Diagrams"},            // Visio Drawing (newer version)
            {".mm", "MindMaps"},              // FreeMind mind map
            {".xmind", "MindMaps"},           // XMind mind map
            {".bpmn", "ProcessModeling"},     // Business Process Model and Notation
            {".tex", "Typesetting"},          // LaTeX source
            {".sty", "LaTeXStyles"},          // LaTeX Style file
            {".cls", "LaTeXClasses"},         // LaTeX Class file
            {".bst", "BibliographyStyles"},   // BibTeX Style file
            {".csl", "CitationStyles"},       // Citation Style Language file
        };

        // Loop to map .type with Subdirectory name
        for (const auto &[extension, directory] : fileTypeToDirectory)
        {
            if (file.extension().string() == extension)
            {
                std::cout << "Matched file type: " << file.extension().string() << " -> Directory: " << directory << "\n";
                return directory;
            }
        }
        return "Undefine";
    }

public:
    bool moveFileToExistedDir(fs::path parentPath, fs::path file)
    {
        fs::path toFile = fs::path(parentPath / file.filename());
        fs::path toDir = fs::path(parentPath / mapName(file) / file.filename());
        std::cout << toFile;
        try
        {
            if (!fs::is_directory(parentPath))
            {
                std::cerr << "Error: Destination is not a directory. or file move is not a file" << std::endl;
            }
            else
            {
                fs::rename(toFile, toDir);
                std::cout << "Move success fully from " << parentPath << " ->>" << file << "\n";
            }
        }
        catch (const fs::filesystem_error &e)
        {
            std::cerr << e.what() << '\n';
        }
        return false;
    }

public:
    void createSubdir(const fs::path &file, const fs::path thisPath)
    {
        std::string file_type = file.extension().string();
        std::string directory = mapName(thisPath); // Get the directory based on file extension
        // fs::path file_path = file.parent_path();       // Get the directory part of the file
        fs::path pathCreation = file / directory; // Properly append the new subdirectory
        try
        {
            // std::string pathCreation = file_path.append("/").append(mapName(file_type));
            if (!fs::exists(mapName(file)))

                if (fs::create_directories(pathCreation))
                    std::cout << "Create subdir success :" << pathCreation << "\n";
                else
                    std::cout << "Fail to create :" << pathCreation << "\n";
            else
                std::cout << "Move file to existed subdirectory :" << pathCreation << "\n";
        }
        catch (const fs::filesystem_error err)
        {
            std::cerr << err.what() << '\n';
        }
    }
    // List all directory and subdirectory
    // If do not have permission -> skip
public:
    std::vector<fs::path> listAllPaths(const fs::path &dirpath)
    {
        std::vector<fs::path> paths;
        try
        {
            for (const auto &entry : fs::directory_iterator(dirpath))
            {
                paths.push_back(entry.path());
                if (fs::is_directory(entry))
                {
                    std::cout<<"Is directory ->> Skip ";
                    // std::vector<fs::path> subPaths = listAllPaths(entry.path());
                    // paths.insert(paths.end(), subPaths.begin(), subPaths.end());
                }
            }
        }
        catch (const fs::filesystem_error &e)
        {
            std::cerr << e.what() << '\n';
        }
        return paths;
    }

public:
    void listPath(const fs::path &dirpath)
    {
        std::string rootPath = dirpath;
        // Fix infinite recursion
        std::vector<fs::path> paths = listAllPaths(dirpath);

        try
        {
            for (const auto &entry :
                 fs::directory_iterator(dirpath))
            {
                std::cout << "File :" << entry << "\n";
                if (fs::is_directory(entry.status()))
                {
                    // Declared permission -> permiss
                    fs::perms permiss = fs::status(entry.path()).permissions();
                    // Check if have permission to read? Yes  -> std::cout
                    if ((permiss & read_perm) != fs::perms::none)
                    {
                        std::cout << "---------------------------\nSubdirectory :" << entry.path().extension().string() << "\n";
                        // listPath(entry.path());
                    }
                    else
                    {
                        // No -> std::notice & skip it
                        std::cout << "You don't have permission to read -- SKIP ->";
                        continue;
                    }
                }
                createSubdir(dirpath, entry);
                // Test create subdir
                // @fix infinite loop recursion
                for (const auto &path : paths)
                {
                    // Fix infinite recursion
                    if (fs::is_regular_file(path))
                    {
                        moveFileToExistedDir(dirpath, path);
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
// Pass paramters runtime
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Path can't be empty";
        return 1;
    }
    // Declare
    Structura p;
    std::string orpath = argv[1];
    std::cout << "Path: ";
    char cf;
    // Pass parameters for path
    fs::path dirpath = orpath;
    // Confirm path
    std::cout << "Are you sure to restruct" << orpath << " ? " << "(Y or N)";
    std::cin >> cf;
    if (cf == 'Y')
        if (p.isValidPath(dirpath))
            std::cout << "Path not found ";
        else
        {
            std::cout << "Path found." << std::endl;
            p.listPath(dirpath);
            return 0;
        }
    else
        return 0;
}
