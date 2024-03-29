// In this case, 'FC' does not mean 'Full-Combo'

#include "../../common/consts.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int FreshClone(int argc, char** argv)
{
    unsigned long LEN = MAX_STR_LEN;

    char FormattedLink[MAX_STR_LEN];
    char FullAddr[MAX_LEN];

    if (strcmp(argv[1], "--fc") == 0)
    {
        strcpy(FullAddr, argv[2]);

        snprintf(FormattedLink, LEN, "git clone %s%s.git", Adr, FullAddr);
        system(FormattedLink);
    }

    else if (strcmp(argv[1], "--fc-ng") == 0)
    {
        strcpy(FullAddr, argv[2]);

        snprintf(FormattedLink, LEN, "git clone %s%s", Adr, FullAddr);
        system(FormattedLink);
    }

    return 0;
}
