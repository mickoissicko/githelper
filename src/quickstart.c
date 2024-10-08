#include "../common/consts.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int QuickStart(int argc, char* argv[])
{
    if (argc < 2) return 1;

    unsigned long LEN = MAX_STR_LEN;

    char SystemFormattedMessage[MAX_STR_LEN];
    char SystemFormattedAdd[MAX_STR_LEN];
    char CommitMessage[MAX_STR_LEN];
    char ShowRelation[MAX_STR_LEN];
    char FilePath[MAX_STR_LEN];

    strcpy(CommitMessage, argv[4]); // '--q' _str
    strcpy(ShowRelation,  argv[3]); // '--q' _str
    strcpy(FilePath,      argv[2]); // '--q' _str

    if (strcmp(ShowRelation, "::") == 0)
    {
        snprintf(SystemFormattedMessage, LEN, "git commit -m \"%s\"", CommitMessage);
        snprintf(SystemFormattedAdd, LEN, "git add \"%s\"", FilePath);

        system(SystemFormattedAdd);
        system(SystemFormattedMessage);

        if (argc > 5)
            if (strcmp(argv[5], "!push") == 0)
            {
                system("git push");

                return 0;
            }
    }

    else return 1;

    return 0;
}
