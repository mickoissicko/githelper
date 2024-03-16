#include <stdlib.h>
#include <stdio.h>

void commit()
{
    unsigned long MAX_LN = 2048;

    char buf_1[2048];
    char buf_2[2048];

    int addstr;
    int comstr;

    char* line_1 = NULL;
    char* line_2 = NULL;

    FILE* add;
    FILE* com;

    add = fopen("addfiles", "r");
    com = fopen("commit", "r");

    if (add != NULL && com != NULL)
    {
        while (
            (getline(&line_1, &MAX_LN, add) != -1) && 
            (getline(&line_2, &MAX_LN, com) != -1)
        ){
            snprintf(buf_1, sizeof(buf_1), "git add %s", line_1);
            snprintf(buf_2, sizeof(buf_2), "git commit -m \"%s\"", line_2);

            system(buf_1);
            system(buf_2);
        }

        fclose(add);
        fclose(com);

        if (line_1)
        {
            free(line_1);
        }

        if (line_2)
        {
            free(line_2);
        }
    }
}
