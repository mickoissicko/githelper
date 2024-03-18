// main.c
#include "../common/calls.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        if (strcmp(argv[1], "-cfg") == 0)
        {
            setup();

            return 0;
        }

        printf("Unrecognised argument\n");

        return 0;
    }

    start();

    return 0;
}
