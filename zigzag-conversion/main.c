#include <stdlib.h>
#include <stdio.h>

char *convert(char *s, int numRows);

int main() {

    char *text = "PAYPALISHIRING";
    int numRows = 4;
    char *correctAnswer = "PINALSIGYAHRPI\0";

    printf("\nTEXT   : %s,\nZIG-ZAG: %s,\nCORRECT: %s\n", text, convert(text, numRows), correctAnswer);

    return 0;
}


char *convert(char *s, int numRows) {
    if(numRows == 1) {
        return s;
    }

    int size = 0;
    while(s[size] != '\0') {
        size++;
    }

    char *result = (char *)malloc(sizeof(char) * (size + 1));
    result[size] = '\0';
    int index = 0;

    int jump = (numRows - 1) * 2;

    for(int i = 0; i < numRows; i++) {
        int step = jump - (2 * i);
        for(int j = i; j < size; ) {
            if(step != 0) {
                result[index] = s[j];
                index++;
            }
            j += step;
            step = jump - step;
        }
    }

    return result;
}
