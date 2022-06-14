#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
//Prime Test singlethreaded

bool isPrime(int n);

int main()
{
    struct timeval t1, t2, dt;
    int primes = 0;
    gettimeofday(&t1, NULL);
    for(int i = 0; i < 200000; i++){
        if(isPrime(i)){
            printf("%d\n", i);
            primes++;
        }
    }
    gettimeofday(&t2, NULL);
    timersub(&t2, &t1, &dt);
    printf("%ld.%08ld seconds\n", dt.tv_sec, dt.tv_usec);
    printf("number of primes: %d", primes);
    return 0;
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