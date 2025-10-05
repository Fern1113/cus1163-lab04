#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 64
#define MAX_CMD_LENGTH 256

int execute_command(char *command, char **args);

#endif
