#include <stdio.h>
#include <ctype.h>

int main() {
    char str[200];
    int digits = 0, vowels = 0, symbols = 0, i = 0;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    while (str[i] != '\0') {
        if (isdigit(str[i])) {
            digits++;
        }
        else if (isalpha(str[i])) {
            char ch = tolower(str[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            }
        }
        else if (!isspace(str[i])) {
            symbols++;
        }
        i++;
    }
    
    printf("Digits : %d\n", digits);
    printf("Vowels : %d\n", vowels);
    printf("Symbols : %d\n", symbols);
    
    return 0;
}