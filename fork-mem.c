#include <stdio.h> //printf
#include <unistd.h> //fork
#include <sys/types.h> //pid_t
#include <sys/wait.h> //wait

int value = 2048;


int main() {
  pid_t pid;
  pid = fork(); //Save the child's PID

  if (pid == 0){//Fork gave me 0, I'm the child process
    value += 42;
    printf("Child:  %d\n", value);
  }
  else if (pid > 0){//fork() gave me an ID (assured to be >0), I'm the parent process
    wait(NULL);//Wait for child processes
    printf("Parent: %d\n", value);
  }

  return 0;
}

