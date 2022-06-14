#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
int main() {
    //2
    int number = 123;
    printf("%08d\n", number);

    //03
    printf("before sleep\n");
    sleep(3);
    printf("after sleep\n");

    //04
    srand(time(0));
    int random = (rand() % (1000-500+1) + 500);
    printf("%d\n", random);


    return 0;
}
