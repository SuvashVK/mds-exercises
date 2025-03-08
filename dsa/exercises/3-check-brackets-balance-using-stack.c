/*
    3. Write a program to check an expression for balanced brackets.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 50

char stack[MAXSIZE];
int top = -1;

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(char item)
{
    stack[++top] = item;
}

char pop()
{
    if (isEmpty())
        return stack[top];
    else
        return stack[top--];
}

// Function to check if brackets are balanced
int checkBalance(char expression[])
{
    for (int i = 0; i < strlen(expression); i++)
    {
        char ch = expression[i];

        // Push opening brackets onto stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            // Pop from stack and check matching
            char top = pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return 0; // poped bracked does not match
            }
        }
    }

    return top == -1; // If stack is empty, brackets are balanced
}

int main()
{
    int choice;
    char expression[MAXSIZE];

    while (1)
    {
        printf("-----Menu-----\n");
        printf("1. Check brackets balance\n");
        printf("2. Clear\n");
        printf("3. Exit\n");
        printf("Enter a choice (1-3):");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter an expression: ");
            scanf("%s", expression);

            if (checkBalance(expression))
            {
                printf("Expression has balanced brackets\n\n");
            }
            else
            {
                printf("Expression does not have balanced brackets\n\n");
            }
            break;
        case 2:
            system("clear");
            break;
        case 3:
        default:
            exit(0);
        }
    }

    return 0;
}
