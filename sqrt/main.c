#include <stdio.h>

int mySqrt(int x);

int main() {
 
  int x = 4096*4096;
  int result = mySqrt(x);

  printf("x: %d ==> %d\n", x, result); 
    
  return 0;
}

int mySqrt(int x) {
  long lastValue = 0;
  while(lastValue * lastValue <= x) {
    lastValue += 1;
  }
  return lastValue-1;
}
