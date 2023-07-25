#include "serialize.h"

char* serialize_record(const student_record *source) {
    /* 
    char id_str[64];
    char grade_str[100];

    sprintf(id_str, "%llx", source->id);
    sprintf(grade_str, "%f", source->grade);
    */
    // Static allocation
    static char record_str[RECORD_BUFFER];
    snprintf(
        record_str, RECORD_BUFFER, "%llx;%s;%s;%f", 
        (unsigned long long)source->id,
        source->lastname,
        source->firstname,
        source->grade
    );
    if (strlen(record_str) > 0)
        return record_str;
    return NULL;
}

student_record* deserialize_record(char *source) {
    student_record *record = (student_record*) malloc(sizeof(student_record));

    if (record == NULL) return NULL;

    char *raw_value = strtok_r(source, SEPARATOR, &source);
    int j = 0;
    while (raw_value != NULL) {
        int status = update_record(raw_value, j, record);
        if (status == -1) {
            free(record);
            return NULL;
        }
        raw_value = strtok_r(NULL, SEPARATOR, &source);
        ++j;
    }

    if (j != 4) {
        free(record);
        return NULL;
    }

    return record;
}