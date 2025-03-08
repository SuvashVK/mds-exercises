#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

int queue[MAXSIZE];
int front = -1, rear = -1;

int isEmpty()
{
    if (rear == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if ((rear + 1) % MAXSIZE == front)
        return 1;
    else
        return 0;
}

void enqueue(int data)
{
    if (isFull())
        printf("Queue is full.\n");
    else
    {
        if (isEmpty())
        {
            rear = front = 0;
            queue[0] = data;
        }
        else
        {
            rear = (rear + 1) % MAXSIZE;
            queue[rear] = data;
        }
    }
}

int dequeue()
{
    int data;
    if (isEmpty())
    {
        printf("Queue is empty.\n");
    }
    else
    {
        data = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAXSIZE;
        printf("Dequeued item is: %d \n", data);
    }

    return data;
}

int peek()
{
    if (isEmpty())
        printf("Queue is empty.\n");

    else
    {
        printf("Front item in queue is: %d\n", queue[front]);
        return queue[front];
    }
}

int main()
{

    int choice;
    int item;

    while (1)
    {
        printf("-----Menu-----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Clear\n");
        printf("5. Exit\n");
        printf("Enter a choice (1-5):");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a value:");
            scanf("%d", &item);

            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            system("clear");
            break;
        case 5:
        default:
            exit(0);
        }
    }

    return 0;
}
