typedef struct args
{
    int start;
    int stop;
} args;

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

void *primeSubroutine(void *arg)
{
    args *n = (args *)arg;
    int *counter = malloc(sizeof(int));
    *counter = 0;
    for(int i = n->start; i < n->stop; i++)
    {
        if(isPrime(i)) {
            (*counter)++;
            //printf("%d\n", i);
        }
    }
    free(n);
    return (void *)counter;
}

