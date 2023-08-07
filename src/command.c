#include "command.h"

#define BUFFER 100

int init_command(command_t command, FILE* db) {
    switch (command) {
        case Unknown:
        case Empty:
            return -1;
        case Help: {
            get_help();
            break;
        }
        case Read:
            return read_from_database(db, "");
        // TODO
        case Add: {
            char prompt[BUFFER];
            student_record record;

            printf("Lastname: ");
            if (fgets(prompt, BUFFER, stdin) == NULL) {
                printf("Error occured. Try again. \n");
                return -1;
            }
            prompt[strcspn(prompt, "\n")] = '\0';
            update_record(prompt, 1, &record);

            printf("Firstname: ");
            if (fgets(prompt, BUFFER, stdin) == NULL) {
                printf("Error occured. Try again. \n");
                return -1;
            }
            prompt[strcspn(prompt, "\n")] = '\0';
            update_record(prompt, 2, &record);

            printf("Grade: ");
            if (fgets(prompt, BUFFER, stdin) == NULL) {
                printf("Error occured. Try again. \n");
                return -1;
            }
            prompt[strcspn(prompt, "\n")] = '\0';
            update_record(prompt, 3, &record);
            return add_to_database(db, &record);
        }
        case Update:
        case Delete:
            printf("Not implemented yet!\n");
            break;
        default: 
            return -1;
    }
    
    return 0;
}

int read_from_database(FILE* db, const char* query) {
    return read_database(db);
}

int add_to_database(FILE* db, const student_record* record) {
    char *raw_record = serialize_record(record);
    if (raw_record == NULL) return -1;
    return add_record_to_database(db, raw_record);
}