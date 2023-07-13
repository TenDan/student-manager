#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SEPARATOR ";\n"
#define BUFFER 100

typedef struct student_record {
    __uint128_t id;
    char lastname[BUFFER];
    char firstname[BUFFER];
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
int update_record(char* raw_value, int field, student_record *record_ptr) {
    switch(field) {
        case 0: {
            __uint128_t new_id = (__uint128_t) atoi(raw_value);
            if (new_id <= 0) return -1;
            record_ptr->id = new_id;
            break;
        }
        case 1:
            strcpy(record_ptr->lastname, raw_value);
            break;
        case 2:
            strcpy(record_ptr->firstname, raw_value);
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

/**
 * Prints out record passed as pointer
 * @param record Record pointer
*/
void print_record(student_record *record) {
    printf("Id: %llx\n", (unsigned long long)record->id);
    printf("Name: %s %s\n", record->firstname, record->lastname);
    printf("Grade: %f\n", record->grade);
}

int print_prompt() {
    printf(" > ");
    char command[BUFFER];
    scanf("%s", command);

    if (strcmp(command, "add") == 0) {
        printf("Adding to database...\n");
    } else if (strcmp(command, "read") == 0) {
        printf("Reading from database...\n");
    } else {
        printf("Unknown command. Try again.\n");
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    char *line = NULL;
    size_t line_len = 0;

    if (argc != 2) {
        fprintf(stderr, "Valid usage: %s <database_file>\n", argv[0]);
        return 1;
    }

    int prompt_status = print_prompt();

    if (prompt_status == -1) {
        return -1;
    }

    FILE *database = fopen(argv[1], "r+");

    if (database == NULL) {
        perror("Error occured");
        return 1;
    }

    int chars_read, line_num = 0;
    while ((chars_read = getline(&line, &line_len, database)) != -1) {
        //printf("Record: %s\n", line);
        
        char *token = strtok(line, SEPARATOR);
        student_record record = { .id = 0, .lastname = "", .firstname = "", .grade = 0. };
        int j = 0;
        while (token != NULL) {
            //printf("%s\n", token);
            if (line_num != 0) {
                int status = update_record(token, j, &record);
                if (status == -1)
                    printf("Failed to update some records\n");
            }
            token = strtok(NULL, SEPARATOR);
            ++j;
        }

        if (line_num != 0) print_record(&record);
        ++line_num;
    }

    printf("\n");

    fclose(database);
    return 0;
}