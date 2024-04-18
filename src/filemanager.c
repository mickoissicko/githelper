#include "../common/calls.h"

#include <stdio.h>
#include <unistd.h>

#define MAX_LEN 4096

void RemoveConfig()
{
    unsigned long LEN = MAX_LEN;

    char GelperFolderPath[MAX_LEN];
    char ConfigFilePath[MAX_LEN];

    char* Path;

    #ifdef _WIN32
        Path = Win32_Path();
    #else
        Path = Posix_Path();
    #endif

    // NOTE TO FUTURE ME:
    // YOU ALMOST ERASED YOUR HOME/ DIR
    //
    // POTENTIALLY DESTRUCTIVE FUNCTION BELOW (IF TOUCHED)
    // DO NOT CHANGE, EVER
    //
    snprintf(ConfigFilePath, LEN, "%s/.mix/gelper/config.txt", Path);
    snprintf(GelperFolderPath, LEN, "%s/.mix/gelper", Path);
    //
    remove(ConfigFilePath);
    rmdir(GelperFolderPath);
    //
    // DO NOT TOUCH COMMANDS
}
