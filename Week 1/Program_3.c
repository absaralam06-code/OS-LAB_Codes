/* Q - Write a C program that creates a child process using fork(). The child process should execute the ls -l command using execlp(), 
while the parent waits for the child to finish using wait(). */

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
