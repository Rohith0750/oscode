#include <stdio.h>
#include <stdlib.h>

int buffer[20];
int n;
int in = 0, out = 0;

// Semaphores
int mutex = 1;
int empty;
int full = 0;

// Semaphore WAIT
void wait(int *s)
{
    while (*s <= 0);   // busy wait
    (*s)--;
}

// Semaphore SIGNAL
void signal(int *s)
{
    (*s)++;
}

void producer()
{
    int item;
    while (in < n)
    {
        wait(&empty);
        wait(&mutex);

        printf("Enter an item: ");
        scanf("%d", &item);

        buffer[in] = item;
        in++;

        signal(&mutex);
        signal(&full);
    }
}

void consumer()
{
    int item;
    while (out < n)
    {
        wait(&full);
        wait(&mutex);

        item = buffer[out];
        printf("Consumed item = %d\n", item);
        out++;

        signal(&mutex);
        signal(&empty);
    }
}

int main()
{
    printf("Enter the value of n: ");
    scanf("%d", &n);

    empty = n;

    producer();
    consumer();

    return 0;
}
