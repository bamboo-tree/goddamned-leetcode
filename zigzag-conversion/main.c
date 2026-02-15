#include <stdlib.h>
#include <stdio.h>

char *convert(char *s, int numRows);

/*
 *  PAYP  AL  ISHI  RI  NG 4
 *  >>>> <<<< >>>> <<<< >>  
 *  
 *  PINALSIGYASRPI
 *
 *  PINALSIGYAHRPI
 */

int main() {

    char *text = "PA";
    int numRows = 2;
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

    for(int i = 0; i < numRows; i++) {
        int step = ((numRows-1)*2) - i - i;
        printf("step: %d, %d\n", step, ((numRows-1)*2 - step));
        for(int j = i; j < size; ) {
            if(step != 0) {
                printf("%c %d, ", s[j], j);
                
                result[index] = s[j];
                index++;
            }
            j += step;
            step = ((numRows-1) * 2) - step;
            printf("\nupdate: %d\n", step);
        }
        printf("\n");
    }

    return result;
}
