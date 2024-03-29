#include "../../common/calls.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LEN 4096

char* GetUsername()
{
    FILE* GelperCfg;

    unsigned long LEN = MAX_LEN;

    char FormattedPath[MAX_LEN];
  
    char* Path;
    char* Username;

    Username = (char*)malloc(MAX_LEN);

    #ifdef _WIN32
        Path = Win32_Path();
        snprintf(FormattedPath, LEN, "%s\\.gelper\\config.txt", Path);
    #else
        Path = Posix_Path();
        snprintf(FormattedPath, LEN, "%s/.gelper/config.txt", Path);
    #endif

    GelperCfg = fopen(FormattedPath, "r");

    if (GelperCfg == NULL)
    {
        perror("Error opening file\n");
        exit(1);
    }

    fgets(Username, LEN, GelperCfg);
    fclose(GelperCfg); 

    return Username;
}

