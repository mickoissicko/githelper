#include "../../common/consts.h"
#include "../../common/calls.h"

#include <filesystem> // i like modern C++
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

namespace fs = std::filesystem;
using namespace std;

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

    ConfigFile = HomeDirectory + "/.gelper/config.txt";
    ConfigPath = HomeDirectory + "/.gelper/";

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
