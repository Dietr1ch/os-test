/**
 * Fork bomb
 *
 * This should make the scheduler cry, it may (should) make your system unresponsive.
 */
#include <unistd.h>

int main(){
  while(1)
    fork();

  return 0;
}
