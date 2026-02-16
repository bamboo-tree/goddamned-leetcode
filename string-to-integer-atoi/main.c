#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int myAtoi(char *s);

int main() {

    char *s = "    -042";
    int result = myAtoi(s);

    printf("%s --> %d\n", s, result);

    return 0;
}

int myAtoi(char *s) {

    unsigned int value = 0;
    int sign = 0;           // 0: default (+), 1: +, -1: -  
    bool reached = false;   // determine if algorithm reached digits

    int index = 0;
    char current = s[index];
    
    while(current != '\0') {
        current = s[index];

        // check if reached digits
        if(current >= '0' && current <= '9') { reached = true; }

        // character different than digit
        if(!reached) {
            switch (current) {
                // whitespace
                case ' ':
                    break;
                
                // - sign
                case '-':
                    if(sign != 0) { return 0; }
                    
                    sign = -1;
                    reached = true;
                    break;
                
                // + sign
                case '+':
                    if(sign != 0) { return 0; }
                    
                    sign = 1;
                    reached = true;
                    break;
                
                // any other no digit character
                default:
                    return ((sign != -1) ? (value) : (-1 * value));
            }
        }
        else {
            // check if current is still a digit
            if(current >= '0' && current <= '9') {
                
                // test value overflow
                long temp = ((long)value * 10) + (current - 48);
                if(temp >= 2147483647 && sign != -1) return  2147483647;
                if(temp >= 2147483648 && sign == -1) return -2147483648;

                value = (int) temp;
            }
            else {
                // digit sequence ended, return the value
                return ((sign != -1) ? (value) : (-1 * value));
            }
        }
        index++;
    }
    
    return ((sign != -1) ? (value) : (-1 * value));
}
