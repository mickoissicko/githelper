/*******************************************************************
* accepted arguments:
*
* -mk, -cl, -ap
*
* argument info:
* -mk: makefiles
* -cl: clean upon exit
* -ap: automatically push changes
*
* special argument:
*
* --all
*
* --all turns all the arguments on
*******************************************************************/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void argparse(int argc, char* argv[])
{
    bool all = false;
    bool cl  = false;
    bool mk  = false;
    bool ap  = false;
}
