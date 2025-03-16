#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int child_pid;
    child_pid = fork();

    if (child_pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (child_pid == 0) {
        printf("Child process successfully created!\n");
        printf("Child PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        wait(NULL);
        printf("Parent process successfully created!\n");
        printf("Child PID = %d, Parent PID = %d\n", child_pid, getpid());
    }

    return 0;
}
