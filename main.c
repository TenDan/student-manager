#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "record.h"
#include "prompt.h"
#include "database.h"
#include "command.h"
#include "help.h"

#define SEPARATOR ";\n"

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Valid usage: %s <database_file>\n", argv[0]);
        return 1;
    }

    int prompt_status = print_prompt();

    if (prompt_status == -1) return -1;

    command_t comm = Empty;
    prompt_status = read_prompt(&comm);

    if (prompt_status == -1) {
        if (comm == Unknown)
            emit_try_help();
        return prompt_status;
    }

    FILE *database = open_database(argv[1], comm);

    if (database == NULL) {
        perror("Error occured");
        return -1;
    }

    int command_status = init_command(comm, database);

    if (command_status == -1) {
        printf("Error occured...\n");
        return command_status;
    }

    printf("\n");

    fclose(database);

    return 0;
}