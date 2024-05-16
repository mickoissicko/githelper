#include "../../common/consts.h"
#include "../../common/calls.h"

#include <filesystem> // i like modern C++
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

namespace fs = std::filesystem;
using namespace std;

#define MAX_PATH_LEN 8192

void InitPaths()
{
    char Cwd[MAX_PATH_LEN];
    getcwd(Cwd, sizeof(Cwd));

    char* Path;

    #ifdef _WIN32
       Path = Win32_Path();
    #else
       Path = Posix_Path();
    #endif

    chdir(Path);

    if (!fs::exists(".mix"))
        fs::create_directory(".mix");

    if (chdir(".mix") != 0)
    {
        std::cerr << "Error" << '\n';
        exit(1);
    }

    if (!fs::exists("gelper"))
        fs::create_directory("gelper");

    chdir(Cwd);
}

int Configger(int argc, char** argv)
{
    char* Path;

    std::string HomeDirectory;
    std::string ConfigFile;
    std::string ConfigPath;
    std::string Username;

    #ifdef _WIN32
       Path = Win32_Path();
    #else
       Path = Posix_Path();
    #endif

    HomeDirectory = Path;

    ConfigFile = HomeDirectory + "/.mix/gelper/config.txt";
    ConfigPath = HomeDirectory + "/.mix/gelper/";

    fs::create_directory(ConfigPath);

    std::ofstream Cfg(ConfigFile);

    if (!(Cfg.is_open()))
    {
        std::cerr << "Could not make directory" << endl;
        return 1;
    }

    if (argc < 3)
    {
        std::cout << "Github Username: ";
        std::cin >> Username;
    }

    else if (argc > 2)
    {
        Username = argv[2];
    }

    Cfg << Username << '\n' << "# Gelper configuration file" << '\n';

    Cfg.close();

    return 0;
}

