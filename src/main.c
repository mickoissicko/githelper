#include "../common/calls.h"
#include <stdio.h>

int main()
{
    char Ui;

    do
    {
        printf("Git Helper [v0.1.3b]\n");
        printf("[1] Start\n");
        printf("[X] Quit\n");

        scanf("%c", &Ui);
    }
    while(
        Ui != '1' &&
        Ui != 'X' && Ui != 'x' &&
        Ui != 'Q' && Ui != 'q'
    );

    switch (Ui)
    {
        case '1':
            cmds();
            break;

        case 'X':
        case 'x':
            break;
        
        case 'Q':
        case 'q':
            break;
    }

    return 0;
}
