#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

#define DEBUG 1

int main(int argCount, char* args){
  int depth = 3;
  while(depth--)
    if(fork() && fork()){
#if DEBUG
      int spaces = 3-depth;
      while(spaces--)
        printf(" ");
      printf("[%d]I'll wait for my child processes\n", getpid());
#endif
      wait(NULL);
      return 0;
    }
  sleep(1);
#if DEBUG
  printf("Spawning zsh\n");
#else
  execl("/bin/zsh", "");
#endif
}
