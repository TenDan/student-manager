#include "database.h"

FILE* open_database(char* db_path, command_t command) {
    // TODO
    switch (command) {
        case Add:
            return fopen(db_path, "a");
        case Read:
            return fopen(db_path, "r");
        case Update:
        case Delete:
            return fopen(db_path, "r+");
        default:
            return NULL;
    }
}

int read_database(FILE* db) {
    size_t line_len = 0;
    char *line = NULL, *token = NULL;
    int chars_read, line_num = 0;

    // Read header of file (column names)
    if ((chars_read = getline(&line, &line_len, db)) != -1) {
        token = strtok(line, SEPARATOR);
        while (token != NULL) {
            if (line_num != 0) break;
            printf("\t%s", token);
            token = strtok(NULL, SEPARATOR);
        }
        printf("\n");
        ++line_num;
    }
    
    line_len = 0;
    free(line);

    // Read content of database and apply it to structure
    while ((chars_read = getline(&line, &line_len, db)) != -1) {
        token = strtok(line, SEPARATOR);
        student_record record = { .id = 0, .lastname = "", .firstname = "", .grade = 0. };

        int j = 0, status = 0;
        while (token != NULL) {
            status = update_record(token, j, &record);
            if (status == -1)
                fprintf(stderr, "%sCorrupted record!%s\n", RED_COLOR, NO_COLOR);
            token = strtok(NULL, SEPARATOR);
            ++j;
        }
        if (status != -1) print_record(&record);
        ++line_num;
        line_len = 0;
        free(line);
    }

    free(line);

    return 0;
}