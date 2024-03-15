#include "../../common/calls.h"
#include "../../common/defs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void autostart()
{
    FILE *Cfg;

    bool Auto = false;

    char Line[MAX_LN_LEN];
    char Auto_On[] = "Autostart: On";

    Cfg = fopen("pref.yml", "r");

    if (Cfg == NULL)
    {
        getpath();
        exit(0);
    }

    while (fgets(Line, MAX_LN_LEN, Cfg))
    {
        if (strstr(Line, Auto_On))
        {
            Auto = true;
        }
    }

    if (Auto)
    {
        bool custom = false;
        cmds(custom);
        exit(0);
    }

    fclose(Cfg);
}
