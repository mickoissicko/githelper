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

    do
    {
        std::cout << "Make files? [y/n]: ";
        std::cin >> Ui;

        if (Ui == 'n' || Ui == 'N')
        {
            std::cout << "...hurry up then" << std::endl;
        }
    }
    while (
        Ui != 'y' && Ui != 'Y' &&
        Ui != 'n' && Ui != 'n'
    );

    if (Ui == 'y' || Ui == 'Y')
    {
        std::ofstream Make1("addfiles");
        Make1.close();

        std::ofstream Make2("commit");
        Make2.close();
    }

    do
    {
        std::cout << "Done editing? [y/n]: ";
        std::cin >> Ui;
    }
    while (
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

    do
    {
        std::cout << "Push? [y/n]: ";
        std::cin >> Ui;
    }
    while (
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
