#include "../common/calls.h"

#include <stdio.h>
#include <stdlib.h>

void CreateTemp()
{
    system("mkdir ~/aur.gelper_tmp");
}

void DeleteTemp()
{
    system("rm -rf ~/aur.gelper_tmp");
}

#define MAX_LEN 4096

void RemoveConfig()
{
    unsigned long LEN = MAX_LEN;

    char* Path;
    char* FinalStr;

    #ifdef _WIN32
       Path = Win32_Path();
    #else
       Path = Posix_Path();
    #endif

    snprintf(FinalStr, LEN, "%s/.gelper/config.txt", Path);

    remove(FinalStr);
}
