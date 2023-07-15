#include "database.h"

FILE* open_database(char* db_path, command_t command) {
    // TODO
    return fopen(db_path, "r+");
}