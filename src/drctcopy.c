#include "../common/consts.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int DirectCopy(int argc, char** argv)
{
    unsigned long LEN = MAX_STR_LEN;

    char FormattedLink[MAX_STR_LEN];
    char Address[MAX_LEN];

    if (strcmp(argv[1], "--dc") == 0)
    {
        strcpy(Address, argv[2]);

        snprintf(FormattedLink, LEN, "git clone %s%s", Adr, Address);
        system(FormattedLink);
    }

    else if (strcmp(argv[1], "--dcg") == 0)
    {
        strcpy(Address, argv[2]);

        snprintf(FormattedLink, LEN, "git clone %s%s.git", Adr, Address);
        system(FormattedLink);
    }

    return 0;
}
