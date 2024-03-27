#include "../../common/consts.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* Win32_Path()
{
    unsigned long LEN = MAX_PATH_LEN;

    char Home[MAX_PATH_LEN];

    char* HomeDrive = getenv("HOMEDRIVE");
    char* HomePath = getenv("HOMEPATH");

    strcat(HomeDrive, HomePath);

    return HomeDrive;
}
