#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define MAX_LN 2048

void commit()
{
    char buf_1[MAX_LN];
    char buf_2[MAX_LN];

    std::string line_1;
    std::string line_2;

    std::ifstream add("addfiles");
    std::ifstream com("commit");

    if (add.is_open() && com.is_open())
    {
        while (std::getline(add, line_1) && std::getline(com, line_2))
        {
            snprintf(buf_1, sizeof(buf_1), "git add %s", line_1.c_str());
            snprintf(buf_2, sizeof(buf_2), "git commit -m \"%s\"", line_2.c_str());

            std::system(buf_1);
            std::system(buf_2);
        }

        add.close();
        com.close();
    }
}
