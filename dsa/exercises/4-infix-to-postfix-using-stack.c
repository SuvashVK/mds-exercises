/*
    4. Write a program to convert an infix expression to postfix.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

char peek()
{
    if (isEmpty())
        return '\0';
    else
        return stack[top];
}

void push(char item)
{
    stack[++top] = item;
}

char pop()
{
    if (isEmpty())
        return '\0';
    else
        return stack[top--];
}

int precedence(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void convertToPostfix(char *infix, char *postfix)
{
    int j = 0; // postfix index

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        // if the character is an operand, add it to postfix
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        // if '(' push to stack
        else if (ch == '(')
        {
            push(ch);
        }
        // if ')' pop from stack until '(' is found
        else if (ch == ')')
        {
            while (peek() != '(')
            {
                postfix[j++] = pop();
            }

            pop(); // remove '('
        }
        // if character is an operator, pop higher precedence operators and push the current operator
        else if (isOperator(ch))
        {
            while (top != -1 && precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null terminate the postfix expression
}

int main()
{
    int choice;
    char infix[MAXSIZE], postfix[MAXSIZE];

    while (1)
    {
        printf("-----Menu-----\n");
        printf("1. Convert infix expression to postfix\n");
        printf("2. Clear\n");
        printf("3. Exit\n");
        printf("Enter a choice (1-3):");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter an infix expression: ");
            scanf("%s", infix);

            convertToPostfix(infix, postfix);
            printf("Equivalent postfix expression is: %s", postfix);
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
