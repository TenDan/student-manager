#ifndef SERIALIZE_H_
#define SERIALIZE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "util.h"
#include "record.h"

#define RECORD_BUFFER 1000

/**
 * Serializes record structure into string value
 * @param source Student's record struct pointer
 * @return Result string, NULL if error occured
*/
char* serialize_record(const student_record *source);

/**
 * Deserialize string into student record struct
 * @param source Raw string that should be deserializable
 * @return Student record pointer, that will receive values from raw string, NULL if error occured
*/
student_record* deserialize_record(char *source);

#endif /* SERIALIZE_H_ */