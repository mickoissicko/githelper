#include "../common/consts.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int QuickStart(int argc, char* argv[])
{
    if (argc < 4) return 1;

    unsigned long LEN = MAX_STR_LEN;

    char SystemFormattedMessage[MAX_STR_LEN];
    char SystemFormattedAdd[MAX_STR_LEN];
    char CommitMessage[MAX_STR_LEN];
    char ShowRelation[MAX_STR_LEN];
    char FilePath[MAX_STR_LEN];

    strcpy(CommitMessage, argv[3]);
    strcpy(ShowRelation,  argv[2]);
    strcpy(FilePath,      argv[1]);

    if (strcmp(ShowRelation, "::") == 0)
    {
        snprintf(SystemFormattedMessage, LEN, "git commit -m \"%s\"", CommitMessage);
        snprintf(SystemFormattedAdd, LEN, "git add \"%s\"", FilePath);

        system(SystemFormattedAdd);
        system(SystemFormattedMessage);
    }

    else return 1;

    return 0;
}
