#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// TODO: do it again.

int* createLps(char* needle, int length);
int strStr(char* haystack, char* needle);

int main() {
    // char* haystack = "abbab";
    // char* needle = "bbb";
    char* haystack = "mississip";
    char* needle = "issip";
    int* lps = createLps(needle, strlen(needle));
    int solution = strStr(haystack, needle);

    printf("Haystack : %s (%d)\n", haystack, strlen(haystack));
    printf("Needle   : %s (%d)\n", needle, strlen(needle));
    printf("LPS table: ");
    for(int i = 0; i < strlen(needle); i++) {
        printf("%d", lps[i]);
    }
    printf("\n");
    printf("Solution : %d\n", solution);

    return 0;
}

int* createLps(char* needle, int length) {
    int* lps = (int *)malloc(sizeof(int) * length);                 // allocate memory for lps table same size as pattern (needle)
    lps[0] = 0;                                                     // first element is always 0
    int preffixEndIndex = 0;                                        // it also is the length of current LPS
    int suffixStartIndex = 1;                                       // set (current index) to 1 hence lps[0] is already set 

    while(suffixStartIndex < length) {                              // iterate through "pattern" array
        if(needle[suffixStartIndex] == needle[preffixEndIndex]) {   // IF last preffix char is EQUAL to first suffix char (in current range [0; n]) then... 
            preffixEndIndex++;                                      // increments length of current lps (also move the preffix frame to the right)
            lps[suffixStartIndex] = preffixEndIndex;                // assign current lps value to length (suffixStartIndex is current position in array indexing)
            suffixStartIndex++;                                     // increment current index (increase suffix frame)
        }
        else{                                                       // IF last prefix char is NOT EQUAL to first suffix char then...
            if(preffixEndIndex != 0) {                              // IF longest preffix is bigger than 0 (it means lps value can be positive)
                preffixEndIndex = lps[preffixEndIndex-1];           // set preffix window (end index) to previous value in lps table
            }
            else {                                                  // IF longest preffix is 0
                lps[suffixStartIndex] = 0;                          // set current preffix value to 0
                suffixStartIndex++;                                 // move to the next array position
            }
        }
    }

    return lps;
}


int strStr(char* haystack, char* needle) {
    int haystackLength = strlen(haystack);
    int needleLength = strlen(needle);

    if(needleLength > haystackLength) return -1;

    int* lps = createLps(needle, needleLength);
    int index = 0;
    int needleIndex = 0;
    while(index < haystackLength) {
        if(haystack[index] == needle[needleIndex]) {
            index++;
            needleIndex++;
        }

        if(needleIndex == needleLength) {
            free(lps);
            return index - needleIndex;
        }
        else if(index < haystackLength && haystack[index] != needle[needleIndex]) {
            if(needleIndex != 0) {
                needleIndex = lps[needleIndex - 1];
            }
            else{
                index++;
            }
        }
    }

    free(lps);
    return -1;
}