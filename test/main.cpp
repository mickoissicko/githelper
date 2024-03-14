#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>

void cmds()
{
    char create_Ui;
    char commit_Ui;

    std::string Path;
    std::string File;
    std::string Message;
    std::string add_FormattedStr;
    std::string com_FormattedStr;

    std::ifstream Pref("cfg/pref");

    Pref >> Path;
    Pref.close();

    std::cout << "Create files? [y/n]: ";
    std::cin >> create_Ui;

    std::cout << "Are you done making changes? [y/n]: ";
    std::cin >> commit_Ui;

    if (create_Ui == 'y' || create_Ui == 'Y')
    {
        std::ofstream MakeAddFiles("addfiles");
        MakeAddFiles.close();

        std::ofstream MakeCommit("commit");
        MakeCommit.close();
    }

    if (commit_Ui == 'y' || commit_Ui == 'Y')
    {
        std::ifstream AddFiles("addfiles");
        std::ifstream Commit("commit");

        while(AddFiles.peek() != EOF)
        {
            AddFiles >> File;            
            add_FormattedStr = "git add " + File;        

            system(add_FormattedStr.c_str());

            while(Commit.peek() != EOF)
            {
                Commit >> Message;
                com_FormattedStr = "git commit -m " + Message;

                system(com_FormattedStr.c_str());
            }
        }

        AddFiles.close();
        Commit.close();
    }
}

int main()
{
    char Ui;

    cmds();

    std::cout << "Push? [y/n]";
    std::cin >> Ui;

    if (Ui == 'y' || Ui == 'Y')
    {
        system("git push");
    }

    else if (Ui == 'n' || Ui == 'N')
    {
        return 0;
    }

    return 0;
}
