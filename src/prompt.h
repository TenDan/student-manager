#ifndef PROMPT_H_
#define PROMPT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1000

typedef enum Command {
    Empty,
    Add,
    Read,
    Update,
    Delete,
    Unknown,
} command_t;

/**
 * Printing the prompt for database management
 * @return Status code, negative value if error occured
*/
int print_prompt();

/**
 * Reading the prompt and applying valid command
 * @param command Command enumerable pointer, mustn't be NULL
 * @return Status code, negative value if error occured
*/
int read_prompt(command_t *command);

#endif /* PROMPT_H_ */