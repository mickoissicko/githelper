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

    getline(add, files);
    addstr = "git add " + files;
    
    add.close();
    
    std::cout << files << std::endl;
    std::cout << addstr << std::endl;

    std::ifstream com("commit");

    getline(com, msg);
    comstr = "git commit -m " + msg;

    com.close();

    std::cout << msg << std::endl;
    std::cout << comstr << std::endl;

    return 0;
}
