// I realise this code is messy, can be improved, and know the ways to make it 'better'
// Or more optimal
// And I know that I shouldn't be nesting If-else statements like that, or using too many
// conditions, and just using exits or returns bla bla bla
// But I won't.

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

    char FormattedCDCommand[MAX_STR_LEN];
    char FormattedRepoAddr[MAX_STR_LEN];
    char FormattedCommand[MAX_STR_LEN];
    char FormattedCheck[MAX_STR_LEN];
    char Repo[MAX_LEN];
    char User[MAX_LEN];
    char Soft[MAX_LEN];

    if (argc < 2)
    {
        return 1;
    }

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

    // Same thing, but this appends '.git' to the end of the repo
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

    // Archlinux User Repository related commands
    // Kind of like an AUR-helper
    // Except it's less-secure, and doesn't do most of the things modern AUR helpers do
    // I'll be using this, though. I think it's easier. (For me, at least)
    else if (strcmp(argv[1], "--aur") == 0)
    {
        CreateTemp();

        printf("Software: ");
        scanf("%s", Soft);

        snprintf(FormattedRepoAddr, LEN, "git clone %s%s.git", Aur, Soft);
        snprintf(FormattedCommand, LEN, "cd ~/aur.gelper_tmp && %s", FormattedRepoAddr);
        snprintf(FormattedCDCommand, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

        system(FormattedCommand);
        system(FormattedCDCommand);

        DeleteTemp();

        return 0;
    }

    // Same usage as the above, but 'nc' means 'no-clean'
    // It won't delete the temp folder after exit
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
            snprintf(FormattedCDCommand, LEN, "cd ~/aur.gelper_tmp/%s && makepkg -si", Soft);

            system(FormattedCommand);
            system(FormattedCDCommand);
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

void CreateTemp()
{
    system("mkdir ~/aur.gelper_tmp");
}

void DeleteTemp()
{
    system("rm -rf ~/aur.gelper_tmp");
}
