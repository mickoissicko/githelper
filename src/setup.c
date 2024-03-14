#include <stdio.h>

void setup()
{
    FILE *Preferences;

    char Mkf;
    char Clf;

    Preferences = fopen("cfg/pref.yml", "w");

    fprintf(Preferences, "# By default, both flags are set to True\n");

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

    switch (Mkf)
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

    fprintf(Preferences, "# Change the value of MakeFiles to false if: \n");
    fprintf(Preferences, "# You do not want the program to automatically make 'commit' and 'addfiles' files\n");
    fprintf(Preferences, "# Change it to true if you do want that behaviour\n");
    fprintf(Preferences, "#\n");
    fprintf(Preferences, "# The cleanup flag just deletes those files upon exit\n");

    fclose(Preferences);
}
