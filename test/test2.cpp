#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>

int main()
{
    std::string addstr;
    std::string comstr;
    std::string files;
    std::string msg;

    std::ifstream add("addfiles");

    add >> files;
    addstr = "git add " + files;
    system(addstr.c_str());



    system("git push");

    return 0;
}
