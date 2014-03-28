/**
 * Sample test using fork()
 */
#include <stdio.h>
#include <unistd.h>

int n = 7;
int main(int argc, char *argv[]){
  printf("%d\n", getpid()); //Main process prints this
  fork();
  printf("%d\n", getpid());
  fork();
  printf("%d\n", getpid()); //How many processes reach this line?
  n++;
  printf("%d\n", n); // Can 'n' be greater than 8?

  return 0;
}
