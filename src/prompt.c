#include "prompt.h"

int print_prompt() {
    printf(" > ");

    return 0;
}

int read_prompt(command_t *command) {
    if (command == NULL) return -1;

    char prompt[BUFFER];

    if (fgets(prompt, BUFFER, stdin) == NULL) {
        printf("Error occured. Try again. \n");
        return -1;
    }

    char *command_str = strtok(prompt, " \n");

    if (strcmp(command_str, "add") == 0) {
        *command = Add;
    } else if (strcmp(command_str, "read") == 0) {
        *command = Read;
    } else if (strcmp(command_str, "help") == 0) {
        *command = Help;
    } else {
        *command = Unknown;
        return -1;
    }

    return 0;
}