#ifndef RECORD_H_
#define RECORD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NAME_BUFFER 100

typedef struct student_record {
    __uint128_t id;
    char lastname[NAME_BUFFER];
    char firstname[NAME_BUFFER];
    float grade;
} student_record;

/**
 * Updates record passed as pointer
 * @param raw_value String value we want to apply to the record
 * @param field Field index (beginning with 0) of the record \
 *      0: id (uint128)
 *      1: lastname (string)
 *      2: firstname (string)
 *      3: grade (float) [must be between 1 and 6 with 0.5 step]
 * @return Status code, negative value means that error occured
*/
int update_record(char* raw_value, int field, student_record *record_ptr);

/**
 * Prints out record passed as pointer
 * @param record Record pointer
*/
void print_record(student_record *record);

#endif /* RECORD_H_ */