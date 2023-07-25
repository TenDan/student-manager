#include "record.h"

student_record* create_record(const char *lastname, const char *firstname, const float grade) {
    if (grade < 1. || grade > 6. || fmod(grade, .5) != 0.) return NULL;
    
    student_record *record = malloc(sizeof(student_record));

    record->id = (__uint128_t) 0;
    strncpy(record->firstname, firstname, NAME_BUFFER);
    strncpy(record->lastname, lastname, NAME_BUFFER);
    record->grade = grade; 

    return record;
}

int update_record(const char *raw_value, const int field, student_record *record_ptr) {
    switch(field) {
        case 0: {
            __uint128_t new_id = (__uint128_t) atoi(raw_value);
            if (new_id <= 0) return -1;
            record_ptr->id = new_id;
            break;
        }
        case 1:
            strncpy(record_ptr->lastname, raw_value, NAME_BUFFER);
            break;
        case 2:
            strncpy(record_ptr->firstname, raw_value, NAME_BUFFER);
            break;
        case 3: {
            double new_grade = atof(raw_value);
            if (new_grade < 1. || new_grade > 6. || fmod(new_grade, .5) != 0.) return -1;
            record_ptr->grade = (float) new_grade;
            break;
        }
        default:
            return -1;
    }
    return 0;
}

void print_record(const student_record *record) {
    char *result = serialize_record(record);
    printf("%s\n", result);
    /* printf("\t%2llx", (unsigned long long)record->id);
    printf("\t%8s\t%9s", record->lastname, record->firstname);
    printf("\t%5f\n", record->grade); */
}