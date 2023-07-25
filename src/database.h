#ifndef DATABASE_H_
#define DATABASE_H_

#include <stdio.h>

#include "command.h"
#include "record.h"
#include "util.h"
#include "header.h"

/**
 * Open embedded in file database
 * @param db_path String path to database file
 * @param command Command on which depends how file will be opened
 * @return File pointer, NULL if error occured
*/
FILE* open_database(const char *db_path, command_t command);

int read_database(FILE* db);

/**
 * Add student's record to database file
 * @param   record_ptr  Pointer to a student's record structure
 * @return  Status code, negative value means that error occured
*/
int add_record_to_database(FILE* db, const char *raw_record);

#endif /* DATABASE_H_ */