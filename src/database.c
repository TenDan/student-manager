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