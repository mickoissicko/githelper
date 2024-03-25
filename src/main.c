// main.c
#include "../common/calls.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("No arguments supplied?\n");
        return 1;
    }

    int index = 1;

    bool keepfile = false;
    bool detached = false;
    bool filenull = false;

    if (strcmp(argv[1], "--q") == 0)
    {
        QuickStart(argc, argv);
        return 0;
    }

    else if (
        strcmp(argv[1], "--c")      == 0 ||
        strcmp(argv[1], "--cg")     == 0 ||
        strcmp(argv[1], "--aur")    == 0 ||
        strcmp(argv[1], "--aur-nc") == 0
    ){
        AdvancedCopy(argc, argv);
    }

    else if (
        strcmp(argv[1], "--dc")  == 0 ||
        strcmp(argv[1], "--dcg") == 0
    ){
        DirectCopy(argc, argv);
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
