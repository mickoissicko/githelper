// main.c
#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char Ui;

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

void start()
{
    bool custom;

    FILE* def;
    FILE* git;

    def = fopen("cfg/pref.yml", "r");

    if (def == NULL)
    {
        custom = true;
        cmds(custom);
        exit(0);
    }

    else
    {
        fclose(def);

        custom = false;
        cmds(custom);
    }

    fclose(def);
}

