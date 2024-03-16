#include "../../common/calls.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
