#include <stdio.h>

void setup()
{
    FILE* Preferences;

    char Mkf;
    char Clf;
    char Psh;

    Preferences = fopen("cfg/pref.yml", "w");

    fprintf(Preferences, "# By default, some flags are true/false\n");

    // auto create
    do
    {
        getchar();

        printf("Always create files? [y/n]: ");
        scanf("%c", &Mkf);
    }
    while(
        Mkf != 'y' &&
        Mkf != 'Y' &&
        Mkf != 'n' &&
        Mkf != 'N'
    );

    switch (Mkf)
    {
        case 'Y':
        case 'y':
            fprintf(Preferences, "MakeFiles: True\n");
            break;
        
        case 'N':
        case 'n':
            fprintf(Preferences, "MakeFiles: False\n");
            break;
    }

    // autoclean
    do
    {
        getchar();

        printf("Cleanup files upon exit? [y/n]: ");
        scanf("%c", &Clf);
    }
    while(
        Clf != 'y' &&
        Clf != 'Y' &&
        Clf != 'n' &&
        Clf != 'N'
    );
    
    switch (Clf)
    {
        case 'Y':
        case 'y':
            fprintf(Preferences, "Cleanup: True\n");
            break;
        
        case 'N':
        case 'n':
            fprintf(Preferences, "Cleanup: False\n");
            break;
    }

    // auto push
    do
    {
        getchar();

        printf("Automatically push? [y/n]: ");
        scanf("%c", &Psh);
    }
    while(
        Psh != 'y' &&
        Psh != 'Y' &&
        Psh != 'n' &&
        Psh != 'N'
    );

    switch (Psh)
    {
        case 'Y':
        case 'y':
            fprintf(Preferences, "AutoPush: On\n");
            break;
        
        case 'N':
        case 'n':
            fprintf(Preferences, "AutoPush: Off\n");
            break;
    }

    // auto start
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
