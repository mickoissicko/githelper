#include "../common/calls.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    char Ui;

    if (argc == 2)
    {
        if (strcasecmp(argv[1], "-cfg") == 0)
        {
            setup();
        }
    }

    autostart();

    while (1)
    {
        printf("Git Helper [v1.1.0]\n");
        printf("Hello user!\n");
        printf("You are seeing this message because you haven't: \n");
        printf("- Configured '.githelper'\n");
        printf("- Or have the 'pref.yml' file in this directory\n");
        printf("Read the docs to find out more!\n");
        printf("\n");
        printf("You can also run GitHelper with '-cfg' to make the configuration file!\n");
        printf("Type X to exit and acknowledge...\n");

        printf("> ");
        scanf("%c", &Ui);

        switch (Ui)
        {
            case 'X':
            case 'x':
                break;
        }

        if (Ui == 'X' || Ui == 'x')
        {
            break;
        }
    }

    return 0;
}
