// Multiple fork() calls (process tree)

#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    printf("PID=%d, Parent=%d\n", getpid(), getppid());
    return 0;
}
