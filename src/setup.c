#include <stdio.h>

void setup()
{
    FILE* Preferences;

    char Mkf;
    char Clf;
    char Psh;

    Preferences = fopen("pref.yml", "w");

    fprintf(Preferences, "# By default, some flags are true/false\n");

    fprintf(Preferences, "MakeFiles: True\n");
    fprintf(Preferences, "Cleanup: True\n");
    fprintf(Preferences, "AutoPush: Off\n");
    fprintf(Preferences, "Autostart: Off\n");

    fprintf(Preferences, "# Autostart can only be changed manually\n");
    fprintf(Preferences, "#\n");
    fprintf(Preferences, "# The Autostart flag automatically starts Gelper\n");
    fprintf(Preferences, "#\n");
    fprintf(Preferences, "# The AutoPush flag pushes the changes automatically in the end\n");
    fprintf(Preferences, "#\n");
    fprintf(Preferences, "# Change the value of MakeFiles to false if: \n");
    fprintf(Preferences, "# You do not want the program to automatically make 'commit' and 'addfiles' files\n");
    fprintf(Preferences, "# Change it to true if you do want that behaviour\n");
    fprintf(Preferences, "#\n");
    fprintf(Preferences, "# The cleanup flag just deletes those files upon exit\n");

    fclose(Preferences);
}
