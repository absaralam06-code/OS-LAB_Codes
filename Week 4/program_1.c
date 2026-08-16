//  Orphan Process

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child (PID %d): my parent (before orphaning) = %d\n",
               getpid(), getppid());

        sleep(3);

        printf("Child (PID %d): my parent NOW = %d (this is 1, or systemd's PID, "
               "meaning I got adopted)\n",
               getpid(), getppid());
    } else {
        printf("Parent (PID %d): exiting immediately, leaving child %d behind\n",
               getpid(), pid);
    }

    return 0;
}
