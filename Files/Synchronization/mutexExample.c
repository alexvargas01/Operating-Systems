#include <stdio.h>
#include <pthread.h>

#define BUFFERSIZE 5
int buffer[BUFFERSIZE];
int count = 0;
int in = 0, out = 0;
pthread_mutex_t lock;

void *producer(void *arg)
{
    int i = 0;
    while (i < 100)
    {
        while (count == BUFFERSIZE); // wait while the buffer is full
        pthread_mutex_lock(&lock);
        buffer[in] = i;
        in = (in + 1) % BUFFERSIZE;
        count++;
        i++;
        pthread_mutex_unlock(&lock);
    }

    return 0;
}

void *consumer(void *arg)
{
    int i = 0;
    while (i < 100)
    {
        while (count == 100); //wait while buffer is empty
        pthread_mutex_lock(&lock);
        int num = buffer[out];
        out = (out + 1) % BUFFERSIZE;
        count--;
        i++;
        printf("%d\n", num);
    }

    return 0;
}

int main()
{
    pthread_mutex_init(&lock, NULL);
    pthread_t p, c;
    pthread_create(&c, NULL, consumer, NULL);
    pthread_create(&c, NULL, producer, NULL);
    pthread_join(c, NULL);
    pthread_join(p, NULL);

    return 0;
}