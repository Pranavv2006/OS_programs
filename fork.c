#include <stdio.h>
#include <stdlib.h>

int fork();
int getpid();

int main(){
    int pid = fork();
    if (pid == 0) {
        // Child process
        printf("This is the child process: PID = %d", getpid());
    } else if (pid > 0) {
        // Parent process
        printf("This is the Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    } else {
        // Fork failed
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    return 0;
}