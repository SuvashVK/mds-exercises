/*
    4. Write a program to convert an infix expression to postfix.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXSIZE 50

int stack[MAXSIZE];
int top = -1;

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int peek()
{
    if (isEmpty())
        return -1;
    else
        return stack[top];
}

void push(int item)
{
    stack[++top] = item;
}

int pop()
{
    if (isEmpty())
        return -1;
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

int applyOperator(int operand1, int operand2, char operator)
{
    switch (operator)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    case '^':
        return operand1 ^ operand2; // For power operation

    default:
        return 0;
    }
}

int evaluate(char *postfix)
{
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        // if the character is a digit, push it to the stack
        if (isdigit(ch))
        {
            push(ch - '0'); // Convert char to integer (ASCII '0' = 48)
        }
        // if the character is an operator, pop two operands and apply the operator
        else if (isOperator(ch))
        {
            int operand2 = pop();
            int operand1 = pop();
            int result = applyOperator(operand1, operand2, ch);
            push(result); // push the result back onto the stack as operand for next operation
        }
    }

    // final result is the only item left in the stack
    return pop();
}

int main()
{
    int choice;
    char infix[MAXSIZE], postfix[MAXSIZE];
    int result;

    while (1)
    {
        printf("-----Menu-----\n");
        printf("1. Evaluate a postfix expression\n");
        printf("2. Clear\n");
        printf("3. Exit\n");
        printf("Enter a choice (1-3):");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a postfix expression: ");
            scanf("%s", postfix);

            result = evaluate(postfix);
            printf("Evaluation of expression %s is: %d\n", postfix, result);
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
