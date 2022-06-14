#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
int main() {
    double tomb[20];
    srand(time(NULL));
    for (int i = 0; i < sizeof(tomb)/sizeof(double); i++) {
        tomb[i] = (double) rand()/RAND_MAX*2.0;
        printf("%lf\n", tomb[i]);
    }

    //szekvenciális
    double osszeg = tomb[0];
    for (int i = 1; i < sizeof(tomb)/sizeof(double); i++) {
        osszeg = osszeg * tomb[i];
    }
    printf("osszeg szekvencia: %lf\n", osszeg);

    //openmp for loop
    osszeg = tomb[0];
    #pragma omp for
    for (int i = 1; i < sizeof(tomb)/sizeof(double); i++) {
        osszeg = osszeg * tomb[i];
    }
    printf("openmp: %lf\n", osszeg);

    return 0;
}
