#include "header.h"

int print_header(char *raw_header) {
    char *raw_value = strtok_r(raw_header, SEPARATOR, &raw_header);
    int j = 0;
    while (raw_value != NULL) {
        printf("\t%s", raw_value);
        raw_value = strtok_r(NULL, SEPARATOR, &raw_header);
        ++j;
    }
    if (j != 4)
        return -1;
    return 0;
}