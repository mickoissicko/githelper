#include "../common/calls.h"
#include <stdio.h>

int main()
{
    char Ui;

    do
    {
        printf("Git Helper [v0.1.2a]\n");
        printf("[1] Start\n");
        printf("[X] Exit\n");

        scanf("%c", &Ui);
    }
    while(
        Ui != '1' &&
        Ui != 'X' || 'x'
    );

    // placeholder function
    /*
        if (Ui == '1')
        {
            printf("Setting up...\n");
            setup();
        }
    */
    
    if (Ui == '1')
    {
        cmds();
    }

    else if (Ui == 'X' || Ui == 'x')
    {
        return 0;
    }

    return 0;
}
