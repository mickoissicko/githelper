#include "../../common/consts.h"

#include <stdlib.h>

char* Win32_Path()
{
    unsigned long LEN = MAX_PATH_LEN;

    char* HomeDirectory = getenv("USERPROFILE");

    return HomeDirectory;
}
