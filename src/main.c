#include "../common/calls.h"
#include <stdio.h>

int main()
{
    char Ui;

    do
    {
        printf("Git Helper [v0.1]\n");
        printf("[1] Setup\n");
        printf("[X] Exit\n");
    }
    while(
        Ui != 'X' || 'x' &&
        Ui != '1'
    );

    if (Ui == '1')
    {
        printf("Setting up...\n");
        setup();
    }

    else if (Ui == 'X' || Ui == 'x')
    {
        return 0;
    }

    return 0;
}
