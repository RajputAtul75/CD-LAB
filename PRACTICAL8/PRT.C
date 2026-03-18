%{
#include <stdio.h>
#include <string.h>
int lines = 0;
int words = 0;
int chars = 0;
%}

%%
[a-zA-Z0-9]+  { words++; chars += strlen(yytext); }
\n            { lines++; chars++; }
.             { chars++; }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    yylex();
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);
    return 0;
}