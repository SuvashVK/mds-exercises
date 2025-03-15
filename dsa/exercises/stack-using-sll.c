#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *top = NULL;

int isempty()
{
    return top == NULL;
}

void peek()
{
    if (isempty())
    {
        printf('Stack is empty');
    }
    else
    {
        printf("Topmost element is: %d", top->info);
    }
}

void push(int val)
{
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->info = val;
    ins->next = NULL;

    ins->next = top;
    top = ins;
}

void pop()
{
    if (isempty())
    {
        printf('Stack is empty');
    }
    else
    {

        struct node *del = top;

        int val = del->info;

        top = top->next;

        free(del);

        printf("Popped element is: %d", val);
    }
}

void display()
{
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, val;
    while (1)
    {
        printf("------MENU------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Clear\n");
        printf("6. Exit\n");
        printf("Enter a choice (1-6):");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push:");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            printf("Elements in the stack:\n");
            display();
            break;
        case 5:
            system("clear");
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}