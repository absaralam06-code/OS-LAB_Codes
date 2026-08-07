/* Demonstraight Of Wait() System Call */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0){
        printf("Child (PID %d): starting work...\n", getpid());
        sleep(2);
        printf("Child (PID %d): work done, exiting with code 5\n", getpid());
        exit(5);
    }
    else if (pid > 0){
        printf("Parent (PID %d): waiting for child %d to finish...\n",getpid(), pid);
        pid_t finished = wait(&status);
        if (WIFEXITED(status)){
            printf("Parent: child %d finished, exit code = %d\n",
                   finished, WEXITSTATUS(status));
        }
    }
    else{
        printf("Fork failed\n");
    }
    return 0;
}
