/*Q- Write a C program using two sequential fork() calls. Predict the number of processes created, draw the process tree, and verify the output.*/

#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    printf("PID=%d, Parent=%d\n", getpid(), getppid());
    return 0;
}
