#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREAD_COUNT 13

void *threadFunc(void *arg)
{
    printf("Thread #%d\n", *(int *)arg);
}

int para_threads(pthread_t threads[]);
int seq_threads(pthread_t threads[]);

int main(int argc, char const *argv[])
{
    pthread_t threads[MAX_THREAD_COUNT];
    para_threads(&threads);
    //seq_threads(&threads);

    return 0;
}

int para_threads(pthread_t threads[])
{
    for (int i = 0; i < MAX_THREAD_COUNT; ++i)
    {
        pthread_create(&threads[i], NULL, threadFunc, &i);
        printf("Thread #%d created\n", i);
    }

    for (int i = 0; i < MAX_THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
}

int seq_threads(pthread_t threads[])
{
    for (int i = 0; i < MAX_THREAD_COUNT; ++i)
    {
        pthread_create(&threads[i], NULL, threadFunc, &i);
        printf("Thread #%d created\n", i);
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
}
