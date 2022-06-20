#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include "prime.h"
//Prime Test multithreaded

int main()
{
    int THREADS;
    for(THREADS = 2; THREADS <= 16; THREADS++){
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
        printf("Threads: %d\n", THREADS);
    printf("%ld.%06ld seconds\n", dt.tv_sec, dt.tv_usec);
    printf("number of primes: %d\n", finalCounter);
    }

    return 0;
}

