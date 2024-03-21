// main.c
#include "../common/calls.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    int index = 1;

    puts("starting...");

    bool keepfile = false;
    bool detached = false;
    bool filenull = false;
    bool genprefs = false;

    while (index < argc)
    {
        if (!strcmp(argv[index], "--d")) detached = true;
        if (!strcmp(argv[index], "--k")) keepfile = true;
        if (!strcmp(argv[index], "-cfg")) genprefs = true;

        //if (!strcmp(argv[index], "--detached")) detached = true;
        //if (!strcmp(argv[index], "--keepfile")) keepfile = true;

        index++;
    }

    if (genprefs)
    {
        setup();
        return 0;
    }

    else if (detached || keepfile)
    {
        argparse(argc, argv);
        return 0;
    }

    start();

    return 0;
}
