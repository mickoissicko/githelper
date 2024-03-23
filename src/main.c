// main.c
#include "../common/calls.h"

#include <string.h>

int main(int argc, char** argv)
{
    int index = 1;

    bool keepfile = false;
    bool detached = false;
    bool filenull = false;

    if (strcmp(argv[1], "--q") == 0)
    {
        QuickStart(argc, argv);
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
        argparse(argc, argv);
        return 0;
    }

    return 0;
}
