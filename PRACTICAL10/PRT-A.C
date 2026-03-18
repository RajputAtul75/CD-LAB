%{
#include <stdio.h>
extern FILE *yyin;  // Input file pointer used by Flex
%}
%%
[0-9]+	{ printf("Number: %s\n", yytext); }
.|\n	{ /* Ignore everything else */ }
%%
int yywrap()
{
    return 1;
}
int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        FILE *file = fopen(argv[1], "r");
        if (!file)
        {
            fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }
    yylex();
    return 0;
}