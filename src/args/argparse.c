/*****************************************************
* To-do list:
* 1. Integrate less ambigous argument names, the list:
*
* -np  = -no-prompt = -no-confirm 
* -mkf = -gen-files = -make-files
*
* 2. Add more arguments:
*
* -cl
*****************************************************/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void commit();
void RegularExecution();
void MkfStage2();

#define MAX_ARG 4

int main(int argc, char** argv)
{
    FILE* f1;
    FILE* f2;

    char Com[] = "commit";
    char Add[] = "addfiles";

    char Ui = '\0';

    bool npr = false;
    bool clr = false;
    bool mkf = false;

    int index = 1;

    while (index < argc)
    {
        if (!strcmp(argv[index], "-mk")) mkf = true;
        if (!strcmp(argv[index], "-np")) npr = true;
        if (!strcmp(argv[index], "-cl")) clr = true;

        index++;
    }

    // debugging purposes
    if (mkf) puts("mkf");
    if (npr) puts("npr");
    if (clr) puts("clr");

    if (mkf)
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
                    MkfStage2();
                    if (clr)
                    {
                        remove(Com);
                        remove(Add);
                    }
                    break;

                case 'N':
                case 'n':
                    break;
            }
        }
    }

    else if (npr)
    {
        f1 = fopen("commit", "w");
        fclose(f1);
        f2 = fopen("addfiles", "w");
        fclose(f2);

        while (Ui != 'Y' && Ui != 'y')
        {
            printf("Done editing? [y]: ");
            scanf("%c", &Ui);
        }

        RegularExecution();

        if (Ui == 'y' || Ui == 'Y')
        {
            remove("addfiles");
            remove("commit");
        }
    }

    else
    {
        RegularExecution();
    }

    return 0;
}

void RegularExecution()
{
    commit();
}

void MkfStage2()
{
    char Ui;

    while (Ui != 'y' && Ui != 'Y')
    {
        getchar();
        printf("Done editing? [y]: ");
        scanf("%c", &Ui);
    }
}
