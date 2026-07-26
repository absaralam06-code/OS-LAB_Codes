/* Q - Use wait()/waitpid() to print the exit status of a child process. Explain, with an example, the difference
between a zombie process and an orphan process. */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);
    } else {
        wait(NULL);
        printf("Child finished, parent exiting\n");
    }

    return 0;
}
