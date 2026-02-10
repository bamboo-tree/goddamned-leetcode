#include <stdlib.h>
#include <stdio.h>

char *longestPalindrome(char *s);

int main() {
    
    char *string = "babad";
    
    char* result = longestPalindrome(string);
    printf("%s - result: %s\n", string, result);

    return 0;
}

char *longestPalindrome(char *s) {
    int size = 0;
    while(s[size] != '\0') {
        size++;
    }

    // size of tested substring
    for(int i = size; i > 0; i--) {
        // move the substring "frame" through base string
        for(int j = 0; j < size-i+1; j++) {
            bool isPalindrome = true;
            // printf("range: [%d, %d]\n", j, i+j-1);
            for(int k = j; k <= i+j-1; k++) {
                int start = k;
                int end = i+j-1-k+j; // that was hard... :')
                // printf("[%d] vs [%d]\n", start, end);
                if(s[start] != s[end]) {
                    isPalindrome = false;
                    break;
                }
            }
            
            // allocate memory and return first palindrome (it's also the biggest one)
            if(isPalindrome) {
                char *result = (char *)malloc(sizeof(char) * (i+1));
                for(int k = 0; k < i; k++) {
                    result[k] = s[k+j];
                }
                result[i] = '\0';

                return result;
            }
        }
    }

    return "";
}

