/*Parent Process Computes the SUM of EVEN and child process computes the sum of ODD NUMBERS using fork */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int n , i;
    int even = 0 , odd = 0;
    printf("Enter the value of n : ");
    scanf("%d",&n);

    pid_t pid = fork();
    if(pid < 0){
        printf("Fork Failed !\n");
        return 1;
    }
    else if(pid == 0){
        for(int i = 1 ; i <= n ; i++){
            if(i%2 != 0){
                odd += i;
            }
        }
        printf("\n Child process(PID : %d)\n");
        printf("SUm of odd number = %d\n");
    }
    else {
        for(int i = 1 ; i <= n ; i++){
            if(i%2 == 0){
                even += i;
            }
        }
        printf("\n Parent process(PID : %d)\n");
        printf("Sum of even number = %d\n");
    }
    return 0;
}
