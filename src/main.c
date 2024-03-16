// main.c
#include "../common/calls.h"

#include <stdio.h>

int main()
{
    char Ui;
    const int INFINITE = 1;
    int err;

    start();
    err = check_files();

    if (err == 1)
    {
        while (INFINITE)
        {
            printf("Git Helper [v1.1.0]\n");
            printf("\n");
            printf("Hello user!\n");
            printf("You are seeing this screen because you haven't: \n");
            printf("- Configured '.githelper'\n");
            printf("- Or have the 'pref.yml' file\n");
            printf("Read the docs to find out more!\n");
            printf("\n");
            printf("Remember: you need to:\n");
            printf("- Configure an absolute path in .githelper\n");
            printf("For example: /home/user/file.txt is correct, but\n");
            printf("~/file.txt isn't");
            printf("Also, the .githelper file can not end in a newline.\n");
            printf("It needs to have the path, no extra characters!\n");
            printf("\n");
            printf("You can also run GitHelper with '-cfg' to make the configuration file!\n");
            printf("Type X to exit and acknowledge...\n");

            printf("> ");
            scanf("%c", &Ui);

            switch (Ui)
            {
                case 'X':
                    return 1;
                case 'x':
                    return 1;
            }
        }
    }

    return 0;
}
