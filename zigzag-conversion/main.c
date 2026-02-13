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

    char *text = "PAYPALISHIRING";
    int numRows = 4;
    char *correctAnswer = "PINALSIGYAHRPI\0";

    printf("TEXT   : %s,\nZIG-ZAG: %s,\nCORRECT: %s\n", text, convert(text, numRows), correctAnswer);


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

    if(size <= 1) {
        return s;
    }

    char *result = (char *)malloc(sizeof(char) * (size+1));
    result[size] = '\0';
    int resultIndex = 0;
    int step = (numRows - 1) * 2;

    for(int i = 0; i < numRows; i++) {
        if(i == 0 || i == numRows-1) {
            if(i == numRows-1 && i % 2 != 0) {
                resultIndex--;
            }

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
