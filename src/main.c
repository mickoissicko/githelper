// main.c
#include "../common/calls.h"

#include <string.h>

int main(int argc, char** argv)
{
    VerifyArguments(argc, argv);

    int index = 1;

    bool keepfile = false;
    bool detached = false;
    bool filenull = false;

    if (
        strcmp(argv[1], "--q") == 0
    ){
        QuickStart(argc, argv);
        return 0;
    }

    else if (
        strcmp(argv[1], "--c")      == 0 ||
        strcmp(argv[1], "--cg")     == 0 ||
        strcmp(argv[1], "--aur")    == 0 ||
        strcmp(argv[1], "--aur-nc") == 0
    ){
        GitClone(argc, argv);
        return 0;
    }

    else if (
        strcmp(argv[1], "--dc")  == 0 ||
        strcmp(argv[1], "--dcg") == 0
    ){
        GitClone(argc, argv);
        return 0;
    }

    else if (
        strcmp(argv[1], "--daur-ng") == 0 ||
        strcmp(argv[1], "--daur")    == 0
    ){
        AurHelper(argc, argv);
        return 0;
    }

    else if (
        strcmp(argv[1], "--global-user") == 0
    ){
        Configger(argc, argv);
        return 0;
    }

    else if (
        strcmp(argv[1], "--reset") == 0
    ){
        RemoveConfig();
        return 0;
    }

    else if (
        strcmp(argv[1], "--clean") == 0
    ){
        DeleteTemp();
        return 0;
    }

    else if (
        strcmp(argv[1], "--m") == 0
    ){
        Multistart(argc, argv);
        return 0;
    }

    while (index < argc)
    {
        if (!strcmp(argv[index], "--d")) detached = true;
        if (!strcmp(argv[index], "--k")) keepfile = true;

        index++;
    }

    if (detached || keepfile)
    {
        ArgParse(argc, argv);
        return 0;
    }

    return 0;
}
