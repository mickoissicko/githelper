// main.c
#include "../common/calls.h"

#include <string.h>

int main(int argc, char** argv)
{
    int index = 1;

    bool keepfile = false;
    bool detached = false;
    bool filenull = false;
    bool genprefs = false;

    if (argc > 1)
    {
        if (strcmp(argv[1], "--q") == 0)
        {
            QuickStart(argc, argv);

            return 0;
        }
    }

    while (index < argc)
    {
        if (!strcmp(argv[index], "--d")) detached = true;
        if (!strcmp(argv[index], "--k")) keepfile = true;
        if (!strcmp(argv[index], "-cfg")) genprefs = true;

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
