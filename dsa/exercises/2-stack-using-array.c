/*
    2. Write a program to implement Stack using array data structure.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top == MAXSIZE - 1)
        return 1;
    else
        return 0;
}

void peek()
{
    if (isEmpty())
        printf("Stack is empty.\n");
    else
        printf("Topmost element is %d\n", stack[top]);
}

void push(int item)
{
    if (isFull())
        printf("Stack is full.\n");
    else
        stack[++top] = item;
}

void pop()
{
    if (isEmpty())
        printf("Stack is empty.\n");
    else
        printf("Popped element is %d\n", stack[top--]);
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("-----Menu-----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Clear\n");
        printf("5. Exit\n");
        printf("Enter a choice (1-5):");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to push:");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            system("clear");
            break;
        case 5:
            exit(0);
        }
    }
}