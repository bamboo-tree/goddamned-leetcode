#include <stdlib.h>
#include <stdio.h>

int strStr(char* haystack, char* needle);

int main() {
    char* haystack = "leetcode";
    char* needle = "ma";

    printf("Haystack : %s\n", haystack);
    printf("Needle   : %s\n", needle);

    int index = strStr(haystack, needle);

    printf("Index    : %d\n", index);

    return 0;
}


int strStr(char* haystack, char* needle) {

    int needleLength = 0;
    while(needle[needleLength] != '\0') {
        needleLength++;
    }
    int haystackLength = 0;
    while(haystack[haystackLength] != '\0') {
        haystackLength++;
    }

    if(needleLength > haystackLength) {
        return -1;
    }

    for(int i = 0; i < haystackLength; i++) {

        int didPass = 1;
        for(int j = 0; j < needleLength; j++) {
            if(haystack[i+j] != needle[j]) {
                didPass = 0;
                break;
            }
        }

        if(didPass == 1) {
            return i;
        }
    }

    return -1;
}