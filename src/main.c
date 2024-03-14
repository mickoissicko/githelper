#include "../common/calls.h"

#include <stdio.h>

int main()
{
    char Ui;

    while (1)
    {
        printf("Git Helper [v1.0.0]\n");
        printf("[1] Start\n");
        printf("[2] Configure\n");
        printf("[R] Reset\n");
        printf("[X] Quit\n");

        scanf("%c", &Ui);

        switch (Ui)
        {
            case '1':
                cmds();
                break;

            case '2':
                setup();
                break;

            case 'X':
            case 'x':
                break;

            case 'R':
            case 'r':
                resetcfg();
                break;

            case 'Q':
            case 'q':
                break;
        }

        if (Ui == 'Q' || Ui == 'q')
        {
            break;
        }

        else if (Ui == 'X' || Ui == 'x')
        {
            break;
        }

        while(getchar() != '\n');
    }

    return 0;
}
