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
    bool FileExists;
    char* f_User; // file user
    char Ui;

    unsigned long LEN = MAX_STR_LEN;

    char FormattedCloneCommand[MAX_STR_LEN];
    char FormattedRepoAddr[MAX_STR_LEN];
    char FormattedLink[MAX_STR_LEN];
    char Repo[MAX_LEN];
    char User[MAX_LEN];

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
        FileExists = VerifyPath();

        if (FileExists)
        {
            f_User = GetUsername();

            strcpy(Repo, argv[2]);
            snprintf(FormattedLink, LEN, "git clone %s%s%s.git", Adr, f_User, Repo);

            FormattedLink[strcspn(FormattedLink, "\n")] = '\0';

            snprintf(FormattedCloneCommand, LEN, "%s/%s.git", FormattedLink, Repo);

            system(FormattedCloneCommand);

            return 0;
        }

        else strcpy(User, argv[2]);

        snprintf(FormattedLink, LEN, "git clone %s%s.git", Adr, User);
        system(FormattedLink);
    }

    else if (strcmp(argv[1], "--dc-ng") == 0)
    {
        FileExists = VerifyPath();

        if (FileExists)
        {
            f_User = GetUsername();

            strcpy(Repo, argv[2]);
            snprintf(FormattedLink, LEN, "git clone %s%s%s", Adr, f_User, Repo);

            FormattedLink[strcspn(FormattedLink, "\n")] = '\0';

            snprintf(FormattedCloneCommand, LEN, "%s/%s", FormattedLink, Repo);

            system(FormattedCloneCommand);

            return 0;
        }

        else strcpy(User, argv[2]);

        snprintf(FormattedLink, LEN, "git clone %s%s", Adr, User);
        system(FormattedLink);
    }

    return 0;
}
