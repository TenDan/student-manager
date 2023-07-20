#ifndef COMMAND_H_
#define COMMAND_H_

typedef enum Command {
    Empty,
    Add,
    Read,
    Update,
    Delete,
    Help,
    Unknown,
} command_t;

#include "database.h"

/**
 * Execute command depending on command argument
 * @param command Enumerate param of command_t
 * @param db Database file pointer
 * @return Status code, negative value if error occured
*/
int init_command(command_t command, FILE* db);

/**
 * Read from database with raw query
 * @param db Database file pointer
 * @param query Raw query string
 * @return Status code, negative value if error occured
*/
int read_from_database(FILE* db, char* query);

// TODO
int add_to_database(FILE* db);

// TODO
int update_in_database(FILE* db);

// TODO
int remove_from_database(FILE* db);

#endif /* COMMAND_H_ */