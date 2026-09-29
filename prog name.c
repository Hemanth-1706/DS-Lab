#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void push(int);
void pop();
void display();

int stack[SIZE], top = -1;

void main()
{
    int value, choice;

    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!");
        }
    }
}

void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow!");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d is inserted into the stack.", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!");
    }
    else
    {
        printf("%d is deleted from the stack.", stack[top]);
        top--;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack Underflow! Stack is empty.");
    }
    else
    {
        printf("Stack elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
