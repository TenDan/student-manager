#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "record.h"

#define SEPARATOR ";\n"
#define BUFFER 1000

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

int main(int argc, char **argv) {
    char *line = NULL;
    size_t line_len = 0;

    if (argc != 2) {
        fprintf(stderr, "Valid usage: %s <database_file>\n", argv[0]);
        return 1;
    }

    int prompt_status = print_prompt();

    if (prompt_status == -1) {
        return -1;
    }

    FILE *database = fopen(argv[1], "r+");

    if (database == NULL) {
        perror("Error occured");
        return 1;
    }

    int chars_read, line_num = 0;
    while ((chars_read = getline(&line, &line_len, database)) != -1) {
        //printf("Record: %s\n", line);
        
        char *token = strtok(line, SEPARATOR);
        student_record record = { .id = 0, .lastname = "", .firstname = "", .grade = 0. };
        int j = 0;
        while (token != NULL) {
            //printf("%s\n", token);
            if (line_num != 0) {
                int status = update_record(token, j, &record);
                if (status == -1)
                    printf("Failed to update some records\n");
            }
            token = strtok(NULL, SEPARATOR);
            ++j;
        }

        if (line_num != 0) print_record(&record);
        ++line_num;
    }

    free(line);

    printf("\n");

    fclose(database);

    return 0;
}