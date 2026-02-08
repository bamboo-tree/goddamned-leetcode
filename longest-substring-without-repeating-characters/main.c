#include <stdlib.h>
#include <stdio.h>

int lengthOfLongestSubstring(char *s);

int main() {

    char* string = "au";

    int max = lengthOfLongestSubstring(string);
    printf("%s, max: %d\n", string, max);

    return 0;
}

int lengthOfLongestSubstring(char *s) {
  
    // longest substring so far 
    int max = 0;

    // start and end index of substring
    int start = 0;
    int end = 0;

    while(s[end] != '\0') {
        if(max == 0) {
            max = 1;
        }


        for(int i = start; i < end; i++) {
            // found repeating char
            if(s[i] == s[end]) {
                printf("FOUND. %d\n", i);
                // update max
                int maxCandidate = end-start;
                if(max < maxCandidate) {
                    max = maxCandidate;
                }

                // move start index
                start = i+1;
                break;
            }
        }
        
        printf("start: %d, end: %d, max: %d\n", start, end, max);

        end++;
    }

    int maxCandidate = end-start;
    if(max < maxCandidate) {
        max = maxCandidate;
    }

    return max;
}

