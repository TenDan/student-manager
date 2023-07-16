#include "command.h"
#include "help.h"

int init_command(command_t command) {
    switch (command) {
        case Unknown:
        case Empty:
            return -1;
        case Help: {
            get_help();
            break;
        }
        default: 
            return -1;
    }
    
    return 0;
}