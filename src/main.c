// main.c
#include "../common/calls.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
        strcmp(argv[1], "--c")        == 0 ||
        strcmp(argv[1], "--c-ng")     == 0 ||
        strcmp(argv[1], "--dc")       == 0 ||
        strcmp(argv[1], "--dc-ng")    == 0
    ){
        GitClone(argc, argv);
        return 0;
    }

    else if (
        strcmp(argv[1], "--fc-ng") == 0 ||
        strcmp(argv[1], "--fc")    == 0
    ){
        FreshClone(argc, argv);
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
        strcmp(argv[1], "--ccgp") == 0 ||
        strcmp(argv[1], "--ccga") == 0 ||
        strcmp(argv[1], "--cgp")  == 0 ||
        strcmp(argv[1], "--cga")  == 0
    ){
        SpecialClone(argc, argv);
        return 0;
    }

    else if (
        strcmp(argv[1], "--f") == 0
    ){
        PullAndRebase(argc, argv);

        return 0;
    }

    else if (
        strcmp(argv[1], "--m") == 0
    ){
        MultiStart(argc, argv);

        for (int i = 1; i < argc; i++)
            if (strcmp(argv[i], "!push") == 0)
                system("git push");

        return 0;
    }

    else if (
        strcmp(argv[1], "list-flags") == 0 ||
        strcmp(argv[1], "/?")         == 0 
    ){
        Help();
        return 0;
    }

    else if (
        strcmp(argv[1], "--ver") == 0
    ){
        printf("v2.3.2 stable");
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

