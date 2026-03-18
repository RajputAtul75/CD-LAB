#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int isValidUsername(const char *username) {
    int i = 0;
    while (username[i] != '\0') {
        if (!isalnum(username[i]) && username[i] != '_') {
            return 0; // Invalid character found
        }
        i++;
    }
    return 1; // Valid username
}

int isValidPassword(const char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int i = 0;
    
    while (password[i] != '\0') {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else {
            hasSpecial = 1;
        }
        i++;
    }
    
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    char username[MAX], password[MAX];
    
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;
    
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;
    
    if (isValidUsername(username)) {
        printf("Username is valid.\n");
    } else {
        printf("Username is invalid. It should contain only alphanumeric characters and underscores.\n");
    }
    
    if (isValidPassword(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is invalid. It should contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
    }
    
    return 0;
}