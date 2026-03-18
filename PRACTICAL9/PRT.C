#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i = 0;
char input[50];

void E();
void E1();
void T();
void T1();
void F();

void match(char expected)
{
    if (input[i] == expected)
        i++;
    else {
        printf("\nSyntax Error\n");
        exit(0);
    }
}

void E()
{
    T();
    E1();
}

void E1()
{
    if (input[i] == '+') {
        match('+');
        T();
        E1();
    }
}

void T()
{
    F();
    T1();
}

void T1()
{
    if (input[i] == '*') {
        match('*');
        F();
        T1();
    }
}

void F()
{
    if (input[i] == '(') {
        match('(');
        E();
        match(')');
    }
    else if (input[i] == 'i' && input[i + 1] == 'd') {
        match('i');
        match('d');
    }
    else {
        printf("\nSyntax Error\n");
        exit(0);
    }
}

int main()
{
    printf("Enter the input string: ");
    scanf("%s", input);
    E();
    if (input[i] == '\0')
        printf("\nParsing Successful\n");
    else
        printf("\nSyntax Error\n");
    return 0;
}