#include "../../common/consts.h"

#include <stdio.h>
#include <stdlib.h>

char* Win32_Path()
{
    char *Home;

    snprintf(Home, MAX_PATH_LEN, "%s%s", getenv("HOMEDRIVE"), getenv("HOMEPATH"));

    return Home;
}
