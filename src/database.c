#include "database.h"

FILE* open_database(const char *db_path, command_t command) {
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

int read_database(FILE *db) {
    size_t line_len = 0;
    char *line = NULL;
    int chars_read = 0/* , line_num = 0 */;

    // Read header of file (column names)
    if ((chars_read = getline(&line, &line_len, db)) != -1) {
        int status = print_header(line);
        if (status == -1) {
            free(line);
            return -1;
        }
        //++line_num;
    }
    printf("\n");
    
    line_len = 0;
    free(line);

    // Read content of database and apply it to structure
    while ((chars_read = getline(&line, &line_len, db)) != -1) {
        student_record *record = deserialize_record(line);
        if (record != NULL) print_record(record);
        else fprintf(stderr, "%sCorrupted record!%s\n", RED_COLOR, NO_COLOR);
        //++line_num;
        line_len = 0;
        free(record);
        free(line);
    }

    free(line);

    return 0;
}

int add_record_to_database(FILE* db, const char *raw_record) {
    fwrite(raw_record, sizeof(char), sizeof(char) * strlen(raw_record), db);
    return 0;
}