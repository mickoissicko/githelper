#include "../common/calls.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUF_SIZE 1024

int main()
{
    char Ui;

    autostart();

    while (1)
    {
        printf("Git Helper [v1.0.4 RC4]\n");
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
    }

    return 0;
}
