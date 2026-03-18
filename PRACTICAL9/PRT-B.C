%{
#include <stdio.h>
int vowel_count = 0;
int consonant_count = 0;
%}
%option noyywrap
%%
[aAeEiIoOuU]	{ vowel_count++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] { consonant_count++; }
\n	{ return 0; }
.	;
%%
int main()
{
    printf("Enter a string: ");
    yylex();
    printf("Number of vowels: %d\n", vowel_count);
    printf("Number of consonants: %d\n", consonant_count);
    return 0;
}