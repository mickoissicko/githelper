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

void RemoveConfig()
{
    char* Path;

    #ifdef _WIN32
       Path = Win32_Path();
    #else
       Path = Posix_Path();
    #endif

    remove(Path);
}
