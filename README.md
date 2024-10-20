# Structura

Structura is a cross-platform C++ program designed to restructure directories based on a given path. It checks if a path is valid and lists its contents.

## Prerequisites

- C++17 or later
- CMake 3.10 or later
- A C++ compiler:
  - Windows: Visual Studio with C++ tools or MinGW
  - macOS: Xcode Command Line Tools or Homebrew GCC
  - Unix-based: GCC or Clang

## Building the Project

### On all platforms:

1. Clone the repository:
   ```
   git clone https://github.com/yourusername/structura.git
   cd structura
   ```

2. Create a build directory:
   ```
   mkdir build
   cd build
   ```

3. Generate the build files with CMake:
   ```
   cmake ..
   ```

### Platform-specific build commands:

#### Windows (Visual Studio):
```
cmake --build . --config Release
```

#### Windows (MinGW), macOS, and Unix-based systems:
```
cmake --build .
```

## Usage

Run the program from the command line, providing a path as an argument:

### Windows:
```
structura.exe C:\path\to\directory
```

### macOS and Unix-based systems:
```
./structura /path/to/directory
```

The program will:
1. Check if the provided path is valid.
2. Ask for confirmation to restructure the directory.
3. If confirmed, list the contents of the directory.

## Project Structure

- `main.cpp`: Contains the main function and program logic.
- `Structura.h` and `Structura.cpp`: Define and implement the `Structura` class, which handles path validation and listing.
- `CMakeLists.txt`: CMake configuration file for building the project.

## Notes

- The program uses the C++17 filesystem library (`<filesystem>`).
- On Windows, make sure to use forward slashes (/) or escaped backslashes (\\) when specifying paths.
- Error handling for invalid paths is implemented.
- The program requires user confirmation before proceeding with restructuring.

## Troubleshooting

- On macOS, if you encounter issues with the filesystem library, make sure you're using a recent version of Xcode or have the latest GCC installed via Homebrew.
- On Windows, ensure you have the latest Visual Studio updates or a recent MinGW-w64 installation.

## Contributing

Feel free to submit issues or pull requests if you find any bugs or have suggestions for improvements.

## Connect With Me

Feel free to connect with me on social media!

[<img align="left" alt="nixrajput | GitHub" width="24px" src="https://raw.githubusercontent.com/nixrajput/nixlab-files/master/images/icons/github-brands.svg" />][github]

[<img align="left" alt="nixrajput | Facebook" width="24px" src="https://raw.githubusercontent.com/nixrajput/nixlab-files/master/images/icons/facebook-brands.svg" />][facebook]

[<img align="left" alt="nixrajput | LinkedIn" width="24px" src="https://raw.githubusercontent.com/nixrajput/nixlab-files/master/images/icons/linkedin-in-brands.svg" />][linkedin]

[<img align="left" alt="nixrajput | Instagram" width="24px" src="https://raw.githubusercontent.com/nixrajput/nixlab-files/master/images/icons/instagram-brands.svg" />][instagram]

[github]: https://github.com/hiamchubbybear.git
[facebook]: https://facebook.com/hiamchubbybear
[instagram]: https://www.instagram.com/chessy.1603/
[linkedin]: https://www.linkedin.com/in/huy-tran-423a402a4/
<br>
---
