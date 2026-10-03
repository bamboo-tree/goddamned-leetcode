#include <stdio.h>

char findTheDifference(char* s, char* t);

int main() {
    char* s = "abcd\0";
    char* t = "abcde\0";
    char answ = findTheDifference(s, t);

    printf("answ: %c\n", answ);

    return 0;
}

char findTheDifference(char* s, char* t) {
    char answ = 0;
    int i = 0;
    while(s[i] != '\0') { // s is shorter
        answ ^= s[i];
        answ ^= t[i];
        i++;
    }
    answ ^= t[i];

    return answ;
}
