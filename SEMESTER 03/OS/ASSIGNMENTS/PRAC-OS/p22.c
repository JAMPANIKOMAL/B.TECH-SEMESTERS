#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For fork(), getpid(), getppid()
int main() {
pid_t pid;
// Create a new process
pid = fork();
if (pid < 0) {
// Fork failed
perror("Fork failed");
exit(1);
} else if (pid == 0) {
// This is the child process
printf("Child Process:\n");
printf("Child PID: %d\n", getpid());
printf("Parent PID: %d\n", getppid());
} else {
// This is the parent process
printf("Parent Process:\n");
printf("Parent PID: %d\n", getpid());
printf("Child PID: %d\n", pid);
}
return 0;
}
