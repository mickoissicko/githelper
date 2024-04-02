#include <stdio.h>

void Help()
{
    printf("All accepted arguments:\n");
    printf("[--q] quick start (uses formatting to determine what message to commit for what file):\n");
    printf("    i.e. gelper --q myfile.txt :: 'my message'\n");
    printf("[--d] start a detached session\n");
    printf("    it creates two files, read wiki for more info\n");
    printf("[--k] can be used alongside --d to not delete those files upon exit\n");
    printf("[--dc] directly clone a repository\n");
    printf("[--c] clone a repository without using config\n");
    printf("[-ng] can be appended after above 2 flags to clone without '.git'\n");
    printf("[--(d)aur(-ng)] [-nc] are flags to start aur helper, see wiki\n");
    printf("[--fc(-ng)] directly clone repository without config\n");
    printf("[--global-user] sets a user so '--dc' automatically clones a repository from that user\n");
    printf("    i.e. gelper --global-user github_username");
    printf("    this also makes it so that you don't have to specify your user when you clone a repository\n");
    printf("[--reset] removes the user\n");
    printf("[--clean] deletes AUR temp folder\n");
    printf("[--(c)cga] clones the (user's) about-me (if they have one)\n");
    printf("[--(c)cgp] clones the (user's) website (if they have one)\n");
    printf("[--f] pull and rebase\n");
    printf("[--m] specify more than 1 file and commit a single message for them\n");
    printf("[!push] can be added after (--m,--q,etc.) to push immediately after it adds/commits\n");
    printf("[/?] displays this prompt\n");
    printf("NOTE: please read the official wiki for more info at https://mick.gdn/wiki/githelper!\n");
}

