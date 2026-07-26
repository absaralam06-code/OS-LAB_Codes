/*Q- Write a C program to create a child process using the fork() system call and display the Process ID (PID) of both the parent and child 
processes. */

#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid = fork();
    if (pid < 0) {
      printf("Fork failed\n");
    } 
    else if (pid == 0){
      printf("Child: PID=%d, Parent PID=%d\n", getpid(), getppid());
    }
    else {
      printf("Parent: PID=%d, Child PID=%d\n", getpid(), pid);
    }
return 0;
}
