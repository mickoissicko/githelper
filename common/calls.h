#ifndef CALLS_H
    #define CALLS_H
#include <stdnoreturn.h>
#endif

#include <stdbool.h>

void VerifyArguments(int argc, char* argv[]);
int AdvancedCopy(int argc, char* argv[]);
int DirectCopy(int argc, char* argv[]);
int QuickStart(int argc, char* argv[]);
int Configger(int argc, char* argv[]);
int DirectAUR(int argc, char* argv[]);
int ArgParse(int argc, char* argv[]);

void RegularExecution();
void PromptForPush();
void DeleteTemp();
void CreateTemp();
void StageTwo();
void Commit();

char* Posix_Path();
char* Win32_Path();
