/*
    1. Write a program to find sum and average of n numbers using malloc(), calloc(), realloc(),
    and free() in C.
*/

#include <stdio.h>
#include <stdlib.h>

void displaySumAndAverage(float sum, float avg)
{
    printf("Sum = %.2f\n", sum);
    printf("Average = %.2f\n", avg);
}

int main()
{
    int n, choice, i;
    float sum = 0, avg = 0;
    float *numbers;

    printf("Choose memory allocation:\n");
    printf("1. malloc()\n");
    printf("2. calloc()\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the count of numbers: ");
    scanf("%d", &n);

    switch (choice)
    {
    case 1:
        // use malloc
        numbers = (float *)malloc(n * sizeof(float));
        printf("Allocated memory using malloc()\n");
        break;
    case 2:
        // use calloc
        numbers = (float *)calloc(n, sizeof(float));
        printf("Allocated memory using calloc()\n");
        break;
    default:
        printf("Invalid choice. Exiting ...\n");
        exit(0);
    }

    // exit if memory allocation is failed
    if (numbers == NULL)
    {
        printf("Could not allocate memory. Exiting ...\n");
        exit(0);
    }

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &numbers[i]);
        sum += numbers[i];
    }

    avg = sum / n;

    displaySumAndAverage(sum, avg);

    int newSize;
    printf("\nDo you want to increase array size? If yes, enter new size, else enter 0 to exit: ");
    scanf("%d", &newSize);

    if (newSize > 0)
    {
        if (newSize <= n)
        {
            printf("Invalid size. Exiting ...");
        }
        else
        {
            numbers = (float *)realloc(numbers, newSize * sizeof(float));

            if (numbers == NULL)
            {
                printf("Could not allocate memory. Exiting ...\n");
            }
            else
            {

                printf("Enter %d more numbers:\n", newSize - n);

                for (i = n; i < newSize; i++)
                {
                    scanf("%f", &numbers[i]);
                    sum += numbers[i];
                }

                avg = sum / newSize;
                displaySumAndAverage(sum, avg);
            }
        }
    }

    free(numbers);
    printf("Memory freed successfully!\n");

    return 0;
}