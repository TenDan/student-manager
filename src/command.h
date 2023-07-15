#ifndef COMMAND_H_
#define COMMAND_H_

typedef enum Command {
    Empty,
    Add,
    Read,
    Update,
    Delete,
    Unknown,
} command_t;

#endif /* COMMAND_H_ */