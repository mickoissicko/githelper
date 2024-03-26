// I realise this code is messy, can be improved, and know the ways to make it 'better'...
// But I can't be arsed.

#include "../common/calls.h"
#include "../common/consts.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int AdvancedCopy(int argc, char** argv)
{
    char Ui;
    int Status;

    unsigned long LEN = MAX_STR_LEN;

    char FormattedCdCommand[MAX_STR_LEN];
    char FormattedRepoAddr[MAX_STR_LEN];
    char FormattedCommand[MAX_STR_LEN];
    char FormattedCheck[MAX_STR_LEN];
    char Repo[MAX_LEN];
    char User[MAX_LEN];
    char Soft[MAX_LEN];

    if (strcmp(argv[1], "--c") == 0)
    {
        printf("Username: ");
        scanf("%s", User);

        printf("Repository: ");
        scanf(" %s", Repo);

        snprintf(FormattedRepoAddr, LEN, "git clone %s%s/%s", Adr, User, Repo);
        system(FormattedRepoAddr);

        return 0;
    }

    else if (strcmp(argv[1], "--cg") == 0)
    {
        printf("Username: ");
        scanf("%s", User);

        printf("Repository: ");
        scanf(" %s", Repo);

        snprintf(FormattedRepoAddr, LEN, "git clone %s%s/%s.git", Adr, User, Repo);
        system(FormattedRepoAddr);

        return 0;
    }

    else if (strcmp(argv[1], "--aur") == 0)
    {
        CreateTemp();

        printf("Software: ");
        scanf("%s", Soft);

        snprintf(FormattedRepoAddr, LEN, "git clone %s%s.git", Aur, Soft);
        snprintf(FormattedCommand, LEN, "cd ~/aur.gelper_tmp && %s", FormattedRepoAddr);
        snprintf(FormattedCdCommand, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

        system(FormattedCommand);
        system(FormattedCdCommand);

        DeleteTemp();

        return 0;
    }

    else if (strcmp(argv[1], "--aur-nc") == 0)
    {
        CreateTemp();

        printf("Software: ");
        scanf("%s", Soft);

        snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s", Soft);

        Status = system(FormattedCheck);

        if (Status != 0)
        {
            snprintf(FormattedRepoAddr, LEN, "git clone %s%s", Aur, Soft);
            snprintf(FormattedCommand, LEN, "cd ~/aur.gelper_tmp && %s", FormattedRepoAddr);
            snprintf(FormattedCdCommand, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            system(FormattedCommand);
            system(FormattedCdCommand);
        }

        else
        {
            snprintf(FormattedCheck, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            while (Ui != 'Y' && Ui != 'y' && Ui != 'N' && Ui != 'n')
            {
                printf("Software repository found! Build? [y/n]: ");
                scanf(" %c", &Ui);
            }
            switch (Ui)
            {
                case 'y':
                case 'Y':
                    system(FormattedCheck);
                    break;

                case 'N':
                case 'n':
                    break;
            }
        }
    }

    return 0;
}
