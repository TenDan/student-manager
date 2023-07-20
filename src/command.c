#include "command.h"
#include "help.h"

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
        case Add:
        case Update:
        case Delete:
            printf("Not implemented yet!\n");
            break;
        default: 
            return -1;
    }
    
    return 0;
}

int read_from_database(FILE* db, char* query) {
    return read_database(db);
}