#include "../../common/consts.h"
#include "../../common/calls.h"

#include <stdio.h>

bool VerifyPath()
{ 
    FILE* cfg;

    unsigned long LEN = MAX_LEN;

    char ConfigDirectory[MAX_PATH_LEN];
    char ConfigFilePath[MAX_PATH_LEN];

    char* Path;

    bool FileExists;

    #ifdef _WIN32
        Path = Win32_Path();
    #else
        Path = Posix_Path();
    #endif

    snprintf(ConfigFilePath, LEN, "%s/.mix/gelper/config.txt", Path);
    snprintf(ConfigDirectory, LEN, "%s/.mix/gelper", Path);

    cfg = fopen(ConfigFilePath, "r");

    if (cfg == NULL) FileExists = false;
    
    else 
    {
        FileExists = true;
        fclose(cfg);
    }

    return FileExists;
}

