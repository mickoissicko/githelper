#include "../common/consts.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int MultiStart(int argc, char* argv[])
{
    unsigned long LEN = MAX_STR_LEN;

    char SystemFormattedMessage[MAX_STR_LEN];
    char SystemFormattedAdd[MAX_STR_LEN];
    char RelationDivider[] = "::";

    for (int i = 1; i < argc; i++)
    {
        if (strstr(RelationDivider, argv[i]) == NULL)
        {
            while (i < argc)
            {
                if (i == 1)
                {
                    i++;
                    continue;
                }

                if (strcmp(RelationDivider, argv[i]) == 0) break;

                snprintf(SystemFormattedAdd, LEN, "git add \"%s\"", argv[i]);
                system(SystemFormattedAdd);

                ++i;
            }
        }

        while (i < argc)
        {
            if (strstr(RelationDivider, argv[i]) != NULL)
            {
                ++i;

                while (i < argc)
                {
                    snprintf(SystemFormattedMessage, LEN, "git commit -m \"%s\"", argv[i]);
                    system(SystemFormattedMessage);

                    ++i;
                }
            }

            ++i;
        }
    }

    return 0;
}
