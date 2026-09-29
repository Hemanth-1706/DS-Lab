 #include <stdio.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1; /* Global declarations */

void push(char elem)
{
    stack[++top] = elem; /* Function for PUSH operation */
}

char pop()
{
    return(stack[top--]); /* Function for POP operation */
}

int precedence(char elem)
{
    switch(elem)
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }

    return -1;
}

void main()
{
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;

    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    push('(');

    while((ch = infix[i++]) != '\0')
    {
        if(ch == '(')
        {
            push(ch);
        }
        else if(isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if(ch == ')')
        {
            while(stack[top] != '(')
            {
                postfix[k++] = pop();
            }
            pop(); /* Remove '(' */
        }
        else
        {
            while(precedence(stack[top]) >= precedence(ch))
            {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    while(stack[top] != '(')
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s", postfix);
}
