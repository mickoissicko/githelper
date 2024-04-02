#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/************************************************
* dev notes
*
* dc/dcg
* n(1) dc(2) addr(3)
*
* q
* n(1) q(2) .(3) ::(4) .(5)
*
************************************************/

void VerifyArguments(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Missing flags; type '/?' for a list of flags.");
        printf("Use 'list-flags' if you use the FISH shell\n");
        exit(1);
    }

    else if (strcmp(argv[1], "--q") == 0)
    {
        if (argc < 5)
        {
            printf("Insufficient arguments; type '/?' for a list of flags\n");
            printf("Use 'list-flags' if you use the FISH shell\n");
            exit(1);
        }
    }

    else if (
        strcmp(argv[1], "--dc")         == 0 ||
        strcmp(argv[1], "--dcg")        == 0 ||
        strcmp(argv[1], "--daur")       == 0 ||
        strcmp(argv[1], "--daur-ng")    == 0 ||
        strcmp(argv[1], "--daur-nc")    == 0 ||
        strcmp(argv[1], "--daur-ng-nc") == 0
    ){ 
        if (argc < 3)
        {
            printf("Insufficient arguments!\n");
            printf("See the wiki for correct usage\n");
            exit(1);
        }
    }
}
