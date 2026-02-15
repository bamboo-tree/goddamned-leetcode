#include <stdlib.h>
#include <stdio.h>

int reverse(int x);

int main() {

    printf("sizeof(int) = %d\n", sizeof(int));

    int x = 1410064606;
    int result = reverse(x);

    printf("%d --reverse--> %d\n", x, result);

    return 0;
}

int reverse(int x) {
    
    long result = 0;

    while(x != 0) {
        // check if multiplying is reversable, if not there is an overflow
        int temp = result * 10;
        if(temp / 10 != result) {
            return 0;
        }

        result *= 10;
        result += (x % 10);
        x /= 10;
    }

    return (int) result;
}
