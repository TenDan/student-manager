#include "prompt.h"

int print_prompt() {
    printf(" > ");
    char prompt[BUFFER];

    if (fgets(prompt, BUFFER, stdin) == NULL) {
        printf("Error occured. Try again. \n");
        return -1;
    }

    char *command = strtok(prompt, " \n");

    if (strcmp(command, "add") == 0) {
        printf("Adding to database...\n");
    } else if (strcmp(command, "read") == 0) {
        printf("Reading from database...\n");
    } else {
        printf("Unknown command. Try again.\n");
        return -1;
    }

    return 0;
}