#include "common.h"

#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>

void cmds(bool custom)
{
    char Ui;

    std::string file;
    std::string fn;
    std::string msg;
    std::string comstr;
    std::string addstr;
    std::string conf;

    if (custom)
    {
        std::ifstream GCfg(".githelper");
        getline(GCfg, conf);

        fn = conf;
    }

    else
    {
        fn = "cfg/pref.yml";
    }

    std::ifstream PrefYmlCfg("pref.yml");
    if (PrefYmlCfg.is_open())
    {
        fn = "pref.yml";
    }
    PrefYmlCfg.close();

    std::ifstream YamlCfg(fn);

    getline(YamlCfg, conf); // skip comment
    getline(YamlCfg, conf); // get first flag

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

    commit();

    std::ifstream Yaml(fn);
    getline(Yaml, conf); // skip comment
    getline(Yaml, conf); // skip first flag
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

    std::ifstream PushYn(fn);
    getline(PushYn, conf); // skip comment
    getline(PushYn, conf); // skip first flag
    getline(PushYn, conf); // get cleanup value
    getline(PushYn, conf); // get autopush flag

    if (conf == "AutoPush: Off")
    {
        do
        {
            std::cout << "Push? [y/n]: ";
            std::cin >> Ui;
        }
        while (
            Ui != 'y' &&
            Ui != 'Y' &&
            Ui != 'n' &&
            Ui != 'n'
        );

        if (Ui == 'y' || Ui == 'Y')
        {
            system("git push");
        }
    }

    else if (conf == "AutoPush: On")
    {
        system("git push");
    }

    else
    {
        std::cerr << "Invalid format" << std::endl;
    }
}

void commit()
{
    char buf_1[MAX_LN];
    char buf_2[MAX_LN];

    std::string line_1;
    std::string line_2;

    std::ifstream add("addfiles");
    std::ifstream com("commit");

    if (add.is_open() && com.is_open())
    {
        while (std::getline(add, line_1) && std::getline(com, line_2))
        {
            snprintf(buf_1, sizeof(buf_1), "git add %s", line_1.c_str());
            snprintf(buf_2, sizeof(buf_2), "git commit -m \"%s\"", line_2.c_str());

            std::system(buf_1);
            std::system(buf_2);
        }

        add.close();
        com.close();
    }
}

