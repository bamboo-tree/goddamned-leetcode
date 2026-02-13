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

    char *text = "PAYPALISHIRING\0";
    int numRows = 4;
    char *correctAnswer = "PINALSIGYAHRPI\0";

    printf("TEXT   : %s,\nZIG-ZAG: %s,\nCORRECT: %s\n", text, convert(text, numRows), correctAnswer);


    return 0;
}

char *convert(char *s, int numRows) {

    int size = 0;
    while(s[size] != '\0') {
        size++;
    }
    printf("SIZE: %d\n", size);

    
    char *result = (char *)malloc(sizeof(char) * size);
    int step = (numRows - 1) * 2;

    int resultIndex = 0;
    for(int i = 0; i < numRows; i++) {
        
        if(i == 0 || i == numRows-1) {
            int index = i;
            while(index + step < size) {
                printf("%c --> %d at %d\n", s[index], index, resultIndex);
                result[resultIndex] = s[index];
                resultIndex++;
                index += step;
            }
            printf("%c --> %d at %d\n", s[index], index, resultIndex);
            result[resultIndex] = s[index];
            resultIndex++;
        }
        else {
            int prevResultIndex = resultIndex;

            int index = i;
            while(index + step < size) {
                printf("%c --> %d at %d\n", s[index], index, resultIndex);
                result[resultIndex] = s[index];
                resultIndex += 2;
                index += step;
            }
            printf("%c --> %d at %d\n", s[index], index, resultIndex);
            result[resultIndex] = s[index];
            resultIndex = prevResultIndex + 1;;
            
            index = step - i;
            while(index + step <= size) {
                printf("%c --> %d at %d\n", s[index], index, resultIndex);
                result[resultIndex] = s[index];
                resultIndex += 2;
                index += step;
            }
            printf("%c --> %d at %d\n", s[index], index, resultIndex);
            result[resultIndex] = s[index];
            resultIndex += 2;
        }
        printf("\n========\n");
    }

    return result;
}
