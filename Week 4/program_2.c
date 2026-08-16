// Zombie Process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child (PID %d): exiting now\n", getpid());
        exit(0);
    } else {
        printf("Parent (PID %d): sleeping for 15 seconds WITHOUT calling wait()\n",
               getpid());

        printf("Parent: run 'ps aux | grep defunct' in another terminal now to see the zombie (state Z)\n");

        sleep(15);

        printf("Parent: done sleeping, exiting now (zombie will be cleaned up)\n");
    }

    return 0;
}
