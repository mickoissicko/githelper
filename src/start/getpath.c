#include "../../common/calls.h"
#include "../../common/defs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void getpath()
{
    FILE* Git;
    FILE* Cfg;

    bool Custom;
    bool Auto = false;

    char Line[MAX_LN_LEN];
    char UsrFile[MAX_FN_LEN];
    char Auto_On[] = "Autostart: On";

    Git = fopen(".githelper", "r");

    fgets(Line, MAX_LN_LEN, Git);

    strcpy(UsrFile, Line);

    fclose(Git);

    Cfg = fopen(UsrFile, "r");

    while(fgets(Line, MAX_LN_LEN, Cfg))
    {
        if (strstr(Line, Auto_On))
        {
            Auto = true;
        }
    }

    if (Auto)
    {
        bool custom = true;

        cmds(custom);
    }

    fclose(Cfg);
    exit(0);
}
