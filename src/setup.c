#include <stdio.h>

#define MAXLEN 1024

void setup() {
    FILE *Preferences;
    char data[MAXLEN];

    Preferences = fopen("cfg/pref", "w");

    printf("Path to .git folder: ");
    scanf("%s", &data);

    fwrite(data, sizeof(char), sizeof(data), Preferences);
    fclose(Preferences);
 
    return 0;
}
