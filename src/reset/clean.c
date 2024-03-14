#include <stdio.h>

void resetcfg()
{
    FILE *Preferences;

    Preferences = fopen("cfg/pref.yml", "w");

    fprintf(Preferences, "\n");

    fclose(Preferences);
}
