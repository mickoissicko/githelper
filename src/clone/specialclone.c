#include "../../common/calls.h"
#include "../../common/consts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int SpecialClone(int argc, char** argv)
{
    bool FileExists;

    unsigned long LEN = MAX_STR_LEN;

    char* f_User; // file user

    char FormattedCloneCommand[MAX_STR_LEN];
    char Username[MAX_LEN];
    char Address[MAX_LEN];

    if (strcmp(argv[1], "--cgp") == 0)
    {
        FileExists = VerifyPath(); 

        if (FileExists)
        {
            f_User = GetUsername();

            f_User[strcspn(f_User, "\n")] = '\0';

            snprintf(FormattedCloneCommand, LEN, "git clone %s%s/%s%s", Adr, f_User, f_User, Pgs);
            system(FormattedCloneCommand);

            return 0;
        }

        else if (!FileExists && argc < 3)
            return 1;

        strcpy(Username, argv[2]);

        snprintf(FormattedCloneCommand, LEN, "git clone %s%s/%s%s", Adr, Username, Username, Pgs);
        system(FormattedCloneCommand);
        
        return 0;
    }

    else if (strcmp(argv[1], "--cga") == 0)
    {
        FileExists = VerifyPath();

        if (FileExists)
        {
            f_User = GetUsername();

            f_User[strcspn(f_User, "\n")] = '\0';

            snprintf(FormattedCloneCommand, LEN, "git clone %s%s/%s", Adr, f_User, f_User);
            system(FormattedCloneCommand);

            return 0;
        }

        else if (!FileExists && argc < 3)
            return 1;

        strcpy(Username, argv[2]);

        snprintf(FormattedCloneCommand, LEN, "git clone %s%s/%s", Adr, Username, Username);
        system(FormattedCloneCommand);

        return 0;
    }

    else if (strcmp(argv[1], "--ccga") == 0 || strcmp(argv[1], "--ccgp") == 0)
    {
        if (argc < 3)
            return 1;

        if (strcmp(argv[1], "--ccga") == 0)
        {
            strcpy(Address, argv[2]);

            snprintf(FormattedCloneCommand, LEN, "git clone %s%s/%s", Adr, Address, Address);
            puts(FormattedCloneCommand);

            return 0;
        }

        else
        {
            strcpy(Address, argv[2]);

            snprintf(FormattedCloneCommand, LEN, "git clone %s%s/%s%s", Adr, Address, Address, Pgs);
            puts(FormattedCloneCommand);

            return 0;
        }
    }

    return 0;
}

int main(int argc, char** argv)
{
    SpecialClone(argc, argv);
    return 0;
}

