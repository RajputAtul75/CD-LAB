%{
#include<stdio.h>
int tags = 0;
extern FILE *yyin;
%}

%%
"<"[^>]*>	{ tags++; printf("%s\n", yytext); }
.|\n		{ }
%%

int yywrap(void)
{
    return 1;
}

int main(void)
{
    FILE *f;
    char file[50];
    
    printf("Enter File Name : ");
    scanf("%s", file);
    
    f = fopen(file, "r");
    if(f == NULL)
    {
        printf("File not found\n");
        return 0;
    }
    
    yyin = f;
    yylex();
    printf("\nNumber of html tags: %d\n", tags);
    fclose(yyin);
    
    return 0;
}