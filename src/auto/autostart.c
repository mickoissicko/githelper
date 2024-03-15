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
        alt_cfgger();
        exit(0);
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

void alt_cfgger()
{
    FILE* Dgh; // dot git helper file
    FILE* Pyf; // path to yaml file
    FILE* Cfg;

    bool Auto;

    char Line[MAX_LN_LEN];
    char Auto_On[] = "Autostart: On";
    char Auto_Off[] = "Autostart: Off";
    char* Filename;

    Dgh = fopen(".githelper", "r");

    if (Dgh == NULL)
    {
        printf("'.githelper' file needed if project does not contain YAML configuration files\n");
        exit(1);
    }

    fgets(Line, MAX_LN_LEN, Dgh);
    Filename = Line;
    fclose(Dgh);

    Cfg = fopen(Filename, "r");
    
    if (Cfg == NULL)
    {
        printf("Invalid path provided in '.githelper'!\n");
        exit(1);
    }

    while(fgets(Line, MAX_LN_LEN, Cfg))
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

    fclose(Cfg);
}
