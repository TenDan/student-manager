#ifndef RECORD_H_
#define RECORD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "types.h"
#include "serialize.h"

// Update database functions

/**
 * Add student's record to database file
 * @param   record_ptr  Pointer to a student's record structure
 * @return  Status code, negative value means that error occured
*/
int add_record(student_record *record_ptr);

/**
 * Update student's record in database file
 * @param   id          Id of record to update
 * @param   record_ptr  Pointer to student's record structure
 * @return  Status code, negative value means that error occured
*/
int set_record(__uint128_t id, student_record *record_ptr);

/**
 * Delete student's record from database file
 * @param   id  Id of record to delete
 * @return  Status code, negative value means that error occured
*/
int remove_record(__uint128_t id);

// Update record structures functions

/**
 * Creates record entity
 * @param   lastname    Student's lastname
 * @param   firstname   Student's firstname
 * @param   grade       Student's grade
 * @return  Student record structure pointer, NULL if error occured
*/
student_record* create_record(char *lastname, char *firstname, float grade);

/**
 * Updates record passed as pointer
 * @param   raw_value       String value we want to apply to the record
 * @param   field           Field index (beginning with 0) of the record:
 *      0: id (uint128)
 *      1: lastname (string)
 *      2: firstname (string)
 *      3: grade (float) [must be between 1 and 6 with 0.5 step]
 * @param   record_ptr      Pointer to student's record which will be updated
 * @return  Status code, negative value means that error occured
*/
int update_record(char* raw_value, int field, student_record *record_ptr);

/**
 * Prints out record passed as pointer
 * @param   record  Record pointer
*/
void print_record(student_record *record);

#endif /* RECORD_H_ */