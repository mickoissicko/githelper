#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>

void cmds()
{
    std::string Path;
    std::string File;
    std::string FormattedStr;

    std::ifstream Pref("cfg/pref");

    Pref >> Path;
    Pref.close();

    {   // make files (addfiles && commit)
        std::ofstream MakeAddFiles("addfiles");
        MakeAddFiles.close();

        std::ofstream MakeCommit("commit");
        MakeCommit.close();
    }

    {   // add files
        std::ifstream AddFiles("addfiles");
        
        while(AddFiles.peek() != EOF)
        {
            AddFiles >> File;            
            FormattedStr = "git add " + File;        

            std::ifstream Commit("commit");

            while(Commit.peek() != EOF)
            {
                
            }

            Commit.close();
        }

        AddFiles.close();
    }
}
