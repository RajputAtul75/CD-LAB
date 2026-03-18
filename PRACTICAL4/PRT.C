#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isTerminal(char c) {
    return (c == 'i' || c == '+' || c == '$');
}

int main() {
    char input[50];
    int i = 0;
    char x;
    
    printf("Enter the string (end with $): ");
    scanf("%s", input);
    
    push('$');
    push('E');
    
    printf("\nStack\t\tInput\t\tAction\n");
    
    while (top != -1) {
        x = stack[top];
        printf("\n");
        for (int j = top; j >= 0; j--)
            printf("%c", stack[j]);
        printf("\t\t%s\t\t", &input[i]);
        
        if (x == input[i]) {
            pop();
            i++;
            printf("Match %c", x);
        } else if (x == 'E' && input[i] == 'i') {
            pop();
            push('P');
            push('T');
            printf("E -> T E'");
        } else if (x == 'P' && input[i] == '+') {
            pop();
            push('P');
            push('T');
            push('+');
            printf("E' -> + T E'");
        } else if (x == 'P' && input[i] == '$') {
            pop();
            printf("E' -> ε");
        } else if (x == 'T' && input[i] == 'i') {
            pop();
            push('i');
            printf("T -> id");
        } else {
            printf("ERROR");
            return 0;
        }
    }
    
    if (input[i] == '\0')
        printf("\n\nString Accepted!");
    else
        printf("\n\nString Rejected!");
    
    return 0;
}