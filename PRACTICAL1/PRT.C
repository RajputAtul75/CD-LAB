#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LEN 100

// List of keywords
const char *keywords[] = {
    "int", "float", "char", "double", "if", "else", "for", "while", "return", "void"
};
int keywordCount = 10;

// Check if a string is a keyword
int isKeyword(const char *str) {
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

void printToken(const char *type, const char *lexeme) {
    printf("<%s, \"%s\">\n", type, lexeme);
}

int main() {
    char ch;
    char buffer[MAX_LEN];
    int i;

    printf("Enter C code (end input with Ctrl+D on Linux/Mac or Ctrl+Z then Enter on Windows):\n\n");
    
    while ((ch = getchar()) != EOF) {
        // Skip whitespace
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
            continue;

        // Identifiers / keywords
        if (isalpha(ch) || ch == '_') {
            i = 0;
            buffer[i++] = ch;
            while ((ch = getchar()) != EOF && (isalnum(ch) || ch == '_')) {
                if (i < MAX_LEN - 1)
                    buffer[i++] = ch;
            }
            buffer[i] = '\0';
            if (ch != EOF)
                ungetc(ch, stdin);
            
            if (isKeyword(buffer))
                printToken("KEYWORD", buffer);
            else
                printToken("IDENTIFIER", buffer);
        }
        // Numbers
        else if (isdigit(ch)) {
            i = 0;
            buffer[i++] = ch;
            while ((ch = getchar()) != EOF && isdigit(ch)) {
                if (i < MAX_LEN - 1)
                    buffer[i++] = ch;
            }
            buffer[i] = '\0';
            if (ch != EOF)
                ungetc(ch, stdin);
            printToken("NUMBER", buffer);
        }
        // Comments and division
        else if (ch == '/') {
            char next = getchar();
            if (next == '/') {
                while ((ch = getchar()) != EOF && ch != '\n');
            } else if (next == '*') {
                char prev = 0;
                while ((ch = getchar()) != EOF) {
                    if (prev == '*' && ch == '/')
                        break;
                    prev = ch;
                }
            } else {
                if (next != EOF)
                    ungetc(next, stdin);
                buffer[0] = '/';
                buffer[1] = '\0';
                printToken("OPERATOR", buffer);
            }
        }
        // Two-character operators
        else if (ch == '=' || ch == '!' || ch == '<' || ch == '>' || ch == '&' || ch == '|') {
            char next = getchar();
            buffer[0] = ch;
            buffer[1] = '\0';
            
            if ((ch == '=' && next == '=') || (ch == '!' && next == '=') ||
                (ch == '<' && next == '=') || (ch == '>' && next == '=') ||
                (ch == '&' && next == '&') || (ch == '|' && next == '|')) {
                buffer[1] = next;
                buffer[2] = '\0';
            } else {
                if (next != EOF)
                    ungetc(next, stdin);
            }
            printToken("OPERATOR", buffer);
        }
        // Single-character operators and punctuation
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '%' || ch == ';' ||
                 ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
                 ch == '[' || ch == ']') {
            buffer[0] = ch;
            buffer[1] = '\0';
            
            if (ch == ';' || ch == ',' || ch == '(' || ch == ')' ||
                ch == '{' || ch == '}' || ch == '[' || ch == ']')
                printToken("PUNCTUATION", buffer);
            else
                printToken("OPERATOR", buffer);
        }
        // Preprocessor
        else if (ch == '#') {
            buffer[0] = '#';
            buffer[1] = '\0';
            printToken("PREPROCESSOR", buffer);
        }
        // Unknown
        else {
            buffer[0] = ch;
            buffer[1] = '\0';
            printToken("UNKNOWN", buffer);
        }
    }
    
    return 0;
}