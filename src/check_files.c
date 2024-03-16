#include <stdio.h>
#include <string.h>

#define MAX_LINE 64

int check_files()
{
    char* Line;
    char* Path;    
    int err;

    FILE* def_1;
    FILE* def_2;
    FILE* git;
    FILE* usr;

    def_1 = fopen("cfg/pref.yml", "r");

    if (def_1 == NULL)
    {
        err = 1;
        return err;
    }

    else
    {
        err = 0;
        fclose(def_1);
        return err;
    }

    def_2 = fopen("pref.yml", "r");
    
    if (def_2 == NULL)
    {
        err = 1;
        return err;
    }

    else
    {
        fclose(def_2);
        err = 0;
        return err;
    }

    git = fopen(".githelper", "r");

    if (git == NULL)
    {
        err = 1;
        return err;
    }

    else if (git != NULL)
    {
        fgets(Line, MAX_LINE, git);
        strcpy(Path, Line);

        fclose(git);

        usr = fopen(Path, "r");

        if (usr == NULL)
        {
            err = 1;
            return err;
        }

        else
        {
            fclose(usr);
            err = 0;
            return err;
        }
    }

    else
    {
        fclose(git);
        err = 0;
        return err;
    }

    return err;
}
