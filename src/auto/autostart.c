#include "../../common/calls.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LN_LEN 64

void autostart()
{
    FILE *Cfg;

    bool Auto;

    char Line[MAX_LN_LEN];
    char Auto_On[] = "Autostart: On";
    char Auto_Off[] = "Autostart: Off";

    Cfg = fopen("cfg/pref.yml", "r");

    if (Cfg == NULL)
    {
        exit(1);
    }

    while (fgets(Line, MAX_LN_LEN, Cfg))
    {
        if (strstr(Line, Auto_On))
        {
            Auto = true;
        }

        else if (strstr(Line, Auto_Off))
        {
            Auto = false;
        }
    }

    if (Auto)
    {
        cmds();
        exit(0);
    }

    return;
}
