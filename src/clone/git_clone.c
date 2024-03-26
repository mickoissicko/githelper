// I realise this code is messy, can be improved, and know the ways to make it 'better'...
// But I can't be arsed.

#include "../../common/calls.h"
#include "../../common/consts.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int GitClone(int argc, char** argv)
{
    char Ui;
    int Status;

    unsigned long LEN = MAX_STR_LEN;


    char FormattedCdCommand[MAX_STR_LEN];
    char FormattedRepoAddr[MAX_STR_LEN];
    char FormattedCommand[MAX_STR_LEN];
    char FormattedCheck[MAX_STR_LEN];
    char FormattedLink[MAX_STR_LEN];
    char Address[MAX_LEN];
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

    if (strcmp(argv[1], "--dc") == 0)
    {
        strcpy(Address, argv[2]);

        snprintf(FormattedLink, LEN, "git clone %s%s.git", Adr, Address);
        system(FormattedLink);
    }

    else if (strcmp(argv[1], "--dc-ng") == 0)
    {
        strcpy(Address, argv[2]);

        snprintf(FormattedLink, LEN, "git clone %s%s", Adr, Address);
        system(FormattedLink);
    }

    return 0;
}
