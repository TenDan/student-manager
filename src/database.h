#ifndef DATABASE_H_
#define DATABASE_H_

#include <stdio.h>

#include "command.h"

/**
 * Open embedded in file database
 * @param db_path String path to database file
 * @param command Command on which depends how file will be opened
 * @return File pointer, NULL if error occured
*/
FILE* open_database(char *db_path, command_t command);\

// TODO
int read_database();

#endif /* DATABASE_H_ */