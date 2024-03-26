#include "../../common/consts.h"

#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>

char* Posix_Path()
{
    struct passwd *Home;

    char *Path = NULL;

    if ((Home = getpwuid(getuid())) != NULL)
    {
        Path = (char *)malloc(MAX_STR_LEN);

        if (Path != NULL)
        {
            strcpy(Path, Home->pw_dir);
        }
    }

    return Path;
}
