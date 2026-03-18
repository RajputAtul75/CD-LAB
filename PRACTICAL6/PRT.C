#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

char precedence[7][7] = {
    /* +	-	*	/	i	$ */
    { '>', '>', '<', '<', '<', '>' }, // +
    { '>', '>', '<', '<', '<', '>' }, // -
    { '>', '>', '>', '>', '<', '>' }, // *
    { '>', '>', '>', '>', '<', '>' }, // /
    { '>', '>', '>', '>', '-', '>' }, // i
    { '<', '<', '<', '<', '<', '=' }  // $
};

char operators[] = "+-*/i$";

int getIndex(char symbol)
{
    for (int i = 0; i < 6; i++)
        if (operators[i] == symbol)
            return i;
    return -1;
}

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int main()
{
    char input[50];
    int i = 0;
    char a, b;
    
    printf("Enter the input string (end with $): ");
    scanf("%s", input);
    
    push('$');
    printf("\nStack\tInput\tAction\n");
    printf("------\t------\t------\n");
    
    while (1)
    {
        a = stack[top];
        b = input[i];
        int row = getIndex(a);
        int col = getIndex(b);
        
        stack[top + 1] = '\0';
        printf("%s\t%s\t", stack, &input[i]);
        
        if (precedence[row][col] == '<' || precedence[row][col] == '=')
        {
            push(b);
            i++;
            printf("Shift\n");
        }
        else if (precedence[row][col] == '>')
        {
            pop();
            printf("Reduce\n");
        }
        else
        {
            printf("Error\n");
            break;
        }
        
        if (a == '$' && b == '$')
        {
            printf("\nString Accepted\n");
            break;
        }
    }
    
    return 0;
}