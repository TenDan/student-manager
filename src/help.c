#include "help.h"

void emit_try_help() {
    fputs("\
Unknown command...\n\
Try using 'help' to get more information about available commands\n\
", stdout);
}

void get_help(void) {
    printf("\
List of available commands:\n\
    add             Add record to database\n\
    read            Read records from database\n\
    update          Update record in database\n\
    delete          Delete record from database\n\
    help            Get this prompt\n\
");
}