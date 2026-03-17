#include <stdlib.h>
#include <stdio.h>

/*

n=1  ===> 1
n=2  ===> 2
n=3  ===> 3
n=4  ===> 5
n=5  ===> 8
n=6  ===> 13
n=7  ===> 21
n=8  ===> 34
n=9  ===> 55
n=10 ===> 89

isn't it a fibonacci sequence?

*/

int climbStairs(int n);

int main()
{
  for (int n = 1; n <= 45; n++)
  {
    printf("n=%d ===> %d\n", n, climbStairs(n));
  }

  return 0;
}

/*
// recursion solution (very slow)
int climbStairs(int n)
{
  if (n > 1)
  {
    int x = 1;
    for (int i = 0; i < n - 1; i++)
    {
      x += climbStairs(i);
    }
    return x;
  }

  return 1;
}
*/

int climbStairs(int n)
{
  int prev = 0;
  int next = 1;

  int temp;
  for (int i = 1; i <= n; i++)
  {
    temp = next + prev;
    prev = next;
    next = temp;
  }

  return next;
}