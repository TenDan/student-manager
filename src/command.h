#ifndef COMMAND_H_
#define COMMAND_H_

typedef enum Command {
    Empty,
    Add,
    Read,
    Update,
    Delete,
    Help,
    Unknown,
} command_t;

/**
 * Execute command depending on command argument
 * @param command Enumerate param of command_t
 * @return Status code, negative value if error occured
*/
int init_command(command_t command);

// TODO
int read_from_database();

// TODO
int add_to_database();

// TODO
int update_in_database();

// TODO
int remove_from_database();

#endif /* COMMAND_H_ */