#include "../../common/calls.h"
#include "../../common/consts.h"

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int ArgParse(int argc, char** argv)
{
    FILE* f1;
    FILE* f2;

    char Ui = '\0';

    bool keepfile = false;
    bool detached = false;
    bool filenull = false;

    int index = 1;

    while (index < argc)
    {
        if (!strcmp(argv[index], "--d")) detached = true;
        if (!strcmp(argv[index], "--k")) keepfile = true;

        index++;
    }

    if (detached)
    {
        f1 = fopen("commit", "r");
        f2 = fopen("addfiles", "r");

        if (f1 != NULL) fclose(f1);
        if (f2 != NULL) fclose(f2);
        if (f1 == NULL) filenull = true;
        if (f2 == NULL) filenull = true;
        else filenull = false;

        if (filenull)
        {
            while (Ui != 'y' && Ui != 'Y' && Ui != 'n' && Ui != 'N')
            {
                printf("Make files? [y/n]: ");
                scanf("%c", &Ui);
                switch (Ui)
                {
                    case 'Y':
                    case 'y':
                        f1 = fopen("commit", "w");
                        fclose(f1);

                        f2 = fopen("addfiles", "w");
                        fclose(f2);

                        StageTwo();
                        if (!keepfile)
                        {
                            remove(Com);
                            remove(Add);
                        }
                        break;

                    case 'N':
                    case 'n':
                        StageTwo();
                        if (!keepfile)
                        {
                            remove(Com);
                            remove(Add);
                        }
                        break;
                }
            }
        }

        else
        {
            RegularExecution();

            if (!keepfile)
            {
                remove(Com);
                remove(Add);
            }
        }
    }

    PromptForPush();

    return 0;
}

void RegularExecution()
{
    char Ui;

    printf("loading...\n");
    Commit();
}

void StageTwo()
{
    char Ui;

    while (Ui != 'y' && Ui != 'Y')
    {
        printf("Done editing? [y]: ");
        scanf(" %c", &Ui);
    }

    RegularExecution();
}
