#include <stdbool.h>
#include <stdio.h>

void argcommit(
    bool all,
    bool cl,
    bool mk,
    bool ap
){
    if (all)
    {
        cl = true;
        mk = true;
        ap = true;
    }
}
