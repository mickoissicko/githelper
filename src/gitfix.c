#include <string.h>
#include <stdlib.h>

void PullAndRebase(int argc, char** argv)
{
    if (argc < 2)
        exit(1);

    else if (strcmp(argv[1], "--f") == 0)
    {
        system("git pull");
        system("git rebase");

        exit(0);
    }
}

