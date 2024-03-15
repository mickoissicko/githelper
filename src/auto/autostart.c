#include "../../common/calls.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LN_LEN 64

void autostart()
{
    FILE *Cfg;

    char Line[MAX_LN_LEN];
    char Auto_On[] = "Autostart: On";

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
            printf("on\n");
            exit(0);
        }
    }

    printf("off\n");
}

void alt_cfgger()
{
    FILE* git_file;
    FILE* usr_file;

    char Line[MAX_LN_LEN];
    char Auto_On[] = "Autostart: On";

    git_file = fopen(".githelper", "r");

    fgets(Line, MAX_LN_LEN, git_file);
    fclose(git_file);

    usr_file = fopen(Line, "r");

    while (fgets(Line, MAX_LN_LEN, usr_file))
    {
        if (strstr(Line, Auto_On))
        {
            printf("on\n");
            exit(0);
        }
    }

    printf("off\n");

    fclose(usr_file);
}
