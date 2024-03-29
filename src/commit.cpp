#include "../common/consts.h"

#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void Commit()
{
    char buf_1[MAX_LEN];
    char buf_2[MAX_LEN];

    std::string line_1;
    std::string line_2;

    std::ifstream add("addfiles");
    std::ifstream com("commit");

    if (add.is_open() && com.is_open())
    {
        while (getline(add, line_1) && getline(com, line_2))
        {
            snprintf(buf_1, sizeof(buf_1), "git add \"%s\"", line_1.c_str());
            snprintf(buf_2, sizeof(buf_2), "git commit -m \"%s\"", line_2.c_str());

            system(buf_1);
            system(buf_2);
        }

        add.close();
        com.close();
    }
}
