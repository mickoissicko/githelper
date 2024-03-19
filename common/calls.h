#ifndef CALLS_H
    #define CALLS_H
#endif

#include <stdbool.h>

void argparse(int argc, char* argv[]);

void cmds(bool custom);

void argcommit(
    bool all,
    bool cl,
    bool mk,
    bool ap
);

void commit();
void setup();
void start();
