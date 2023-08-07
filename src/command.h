#ifndef COMMAND_H_
#define COMMAND_H_

#include "types.h"
#include "database.h"
#include "record.h"
#include "help.h"

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
int read_from_database(FILE* db, const char* query);

// TODO
int add_to_database(FILE* db, const student_record* record);

// TODO
int update_in_database(FILE* db);

// TODO
int remove_from_database(FILE* db);

#endif /* COMMAND_H_ */