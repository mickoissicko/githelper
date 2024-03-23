#include <stdlib.h>
#include <stdio.h>

void PromptForPush()
{
    char Ui;

    do
    {
        printf("Push? [y/n]: ");
        scanf(" %c", &Ui);
    }
    while (Ui != 'Y' && Ui != 'y' && Ui != 'N' && Ui != 'n');

    switch (Ui)
    {
        case 'Y':
        case 'y':
            system("git push");
            break;

        case 'N':
        case 'n':
            break;
    }
}
