#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#define THREADS 16
//Prime Test multithreaded

void *primeSubroutine(void *arg);
bool isPrime(int n);

typedef struct args
{
    int start;
    int stop;
} args;

int main()
{
    int limit = 200000;
    pthread_t threads[THREADS];
    int step = limit / THREADS;
    struct timeval t1, t2, dt;
    gettimeofday(&t1, NULL);

    for(int i = 0; i < THREADS; i++)
    {
        args *arg = malloc(sizeof(args));
        (*arg).start = i * step;
        (*arg).stop = (*arg).start + step;
        pthread_create(&threads[i], NULL, primeSubroutine, (void *)arg);
    }

    int finalCounter = 0;
    int *subCounter = malloc(sizeof(int));
    for (int i = 0; i < THREADS; i++)
    {
        pthread_join(threads[i], (void **)&subCounter);
        finalCounter = finalCounter + *subCounter;
    }
    free(subCounter);

    gettimeofday(&t2, NULL);
    timersub(&t2, &t1, &dt);
    printf("%ld.%06ld seconds\n", dt.tv_sec, dt.tv_usec);
    printf("number of primes: %d\n", finalCounter);
    return 0;
}

void *primeSubroutine(void *arg)
{
    args *n = (args *)arg;
    int *counter = malloc(sizeof(int));
    *counter = 0;
    for(int i = n->start; i < n->stop; i++)
    {
        if(isPrime(i)) {
            (*counter)++;
            printf("%d\n", i);
        }
    }
    free(n);
    return (void *)counter;
}

bool isPrime(int n)
{
    int a = 2;
    bool z = true;
    while (a <= n/2){
        if(n % a ==0){
            z = false;
            break;
        }
        a++;
    }
    return z;
}