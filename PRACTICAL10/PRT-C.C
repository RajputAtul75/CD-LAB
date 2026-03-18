%{
#include <stdio.h>
int line_number = 1;
%}

line	.*\n

%%
{line}	{ printf("%10d %s", line_number++, yytext); }
%%

int yywrap()
{
    return 1;
}

int main()
{
    extern FILE *yyin;
    yyin = fopen("input.txt", "r");
    if(yyin == NULL)
    {
        printf("File not found\n");
        return 0;
    }
    yylex();
    return 0;
}