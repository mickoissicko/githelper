#include "../common/calls.h"

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>

void cmds()
{
    char Ui;

    std::string file;
    std::string msg;
    std::string comstr;
    std::string addstr;
    std::string conf;

    std::ifstream YamlCfg("cfg/pref.yml");
    getline(YamlCfg, conf);

    if (conf == "MakeFiles: True")
    {
        std::ofstream Make1("addfiles");
        Make1.close();

        std::ofstream Make2("commit");
        Make2.close();
    }

    else if (conf == "MakeFiles: False")
    {
        do
        {
            std::cout << "Create files? [y/n]: ";
            std::cin >> Ui;
        }
        while(
            Ui != 'Y' && Ui != 'y' &&
            Ui != 'N' && Ui != 'n'
        );

        if (Ui == 'Y' || Ui == 'y')
        {
            std::ofstream Make1("addfiles");
            Make1.close();

            std::ofstream Make2("commit");
            Make2.close();
        }
    }

    else
    {
        std::cerr << "Invalid format" << std::endl;
        exit(1);
    }

    YamlCfg.close();

    do
    {
        std::cout << "Done editing? [y/n]: ";
        std::cin >> Ui;
    }
    while(
        Ui != 'y' && Ui != 'Y'
    );

    std::ifstream Add("addfiles");

    if (Add.is_open())
    {
        while (getline(Add, file))
        {
            addstr = "git add " + file;

            system(addstr.c_str());
        }
    }

    Add.close();

    std::ifstream Com("commit");

    if (Com.is_open())
    {
        while (getline(Com, msg))
        {
            comstr = "git commit -m \"" + msg + "\"";
        
            system(comstr.c_str());
        }
    }

    Com.close();

    std::ifstream Yaml("cfg/pref.yml");

    getline(Yaml, conf); // skip first line
    getline(Yaml, conf); // get cleanup value

    if (conf == "Cleanup: True")
    {
        std::remove("addfiles");
        std::remove("commit");
    }

    else if (conf == "Cleanup: False")
    {
        Yaml.close();
    }

    else
    {
        std::cerr << "Invalid format" << std::endl;
        exit(1);
    }

    Yaml.close();

    do
    {
        std::cout << "Push? [y/n]: ";
        std::cin >> Ui;
    }
    while(
        Ui != 'y' && Ui != 'Y' &&
        Ui != 'n' && Ui != 'n'
    );

    if (Ui == 'y' || Ui == 'Y')
    {
        system("git push");
    }

    else
    {
        return;
    }
}
