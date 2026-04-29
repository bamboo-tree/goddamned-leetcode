#include <stdio.h>

int mySqrt(int x);

int main() {
 
  int x = 4096*4096;
  int result = mySqrt(x);

  printf("x: %d ==> %d\n", x, result); 
    
  return 0;
}

// int mySqrt(int x) {
//   long lastValue = 0;
//   while(lastValue * lastValue <= x) {
//     lastValue += 1;
//   }
//   return lastValue-1;
// }

int mySqrt(int x) {
  long left = 1;
  long right = x;

  while(left <= right) {
    long mid = left + (right - left) / 2;

    if (mid * mid == x) return mid;
    if (mid * mid < x) left = mid + 1;
    if (mid * mid > x) right = mid - 1;
  }

  return right;
}
