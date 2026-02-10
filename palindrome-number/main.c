#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(int x);

int main() {

    int x = 12321;
    bool result = isPalindrome(x);
    
    printf("%d ---> %b\n", x, result);

    return 0;
}

bool isPalindrome(int x) {
    if(x < 0) {
        return false;
    }

    int xCpy = x;
    unsigned int reversed = 0;

    while(x / 10 != 0) {
        reversed = (reversed + x % 10) * 10;
        x /= 10;
    }
    reversed += x;
    
    return xCpy == reversed;
}
