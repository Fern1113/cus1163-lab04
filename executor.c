#include "executor.h"

int execute_command(char *command, char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return -1;
    }

    if (pid == 0) {
        execvp(command, args);
        perror("execvp failed");
        exit(1);
    }

    if (waitpid(pid, &status, 0) == -1) {
        perror("waitpid failed");
        return -1;
    }

    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    } else {
        return -1;
    }
}
