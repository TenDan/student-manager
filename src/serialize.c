#include "serialize.h"

char* serialize_record(student_record* source) {
    /* 
    char id_str[64];
    char grade_str[100];

    sprintf(id_str, "%llx", source->id);
    sprintf(grade_str, "%f", source->grade);
    */
    // Static allocation
    static char record_str[RECORD_BUFFER];
    sprintf(record_str, "%llx;%s;%s;%f", (unsigned long long)source->id, source->lastname, source->firstname, source->grade);
    if (strlen(record_str) > 0)
        return record_str;
    return NULL;
}

student_record* deserialize_record(char* source) {
    return NULL;
}