#include "../../common/calls.h"

#include <stdio.h>

int Configger(int argc, char** argv)
{
   char *Path;

   #ifdef _WIN32
      Path = Win32_Path();
   #else
      Path = Posix_Path();
   #endif

   printf("%s\n", Path);

   return 0;
}
