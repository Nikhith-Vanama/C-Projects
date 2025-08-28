#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

int main() {
    char command[MAX_CMD_LEN];

    while (1) {
        printf("mini-shell> ");
        fflush(stdout);

        if (!fgets(command, sizeof(command), stdin)) {
            break;
        }

        // Remove newline
        command[strcspn(command, "\n")] = 0;

        // Exit
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Run command
        system(command);
    }

    return 0;
}
