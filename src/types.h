#ifndef TYPES_H_
#define TYPES_H_

#define NAME_BUFFER 100

typedef enum Command {
    Empty,
    Add,
    Read,
    Update,
    Delete,
    Help,
    Unknown,
} command_t;

typedef struct student_record {
    __uint128_t id;
    char lastname[NAME_BUFFER];
    char firstname[NAME_BUFFER];
    float grade;
} student_record;

#endif /* TYPES_H_ */