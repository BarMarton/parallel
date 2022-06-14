#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int main() {
    int tomb[20];
    bool isUnique;
    srand(time(0));
    tomb[0] = rand() % 100;
    for(int i = 1; i < sizeof(tomb)/sizeof(int); i++){
        if(rand() % 2 == 0) {
            isUnique = false;
            while (!isUnique) {
                tomb[i] = rand() % 100;
                for (int j = 0; j < i; j++) {
                    if (tomb[j] != tomb[i]) isUnique = true;
                    else {
                        isUnique = false;
                        break;
                    }
                }
            }
        } else{
            tomb[i] = tomb[i-1];
        }
        printf("%d ", tomb[i]);
    }

    for(int i = 1; i < sizeof(tomb)/sizeof(int); i++) {
        for( int j = 0; j < i; j++){
            if(tomb[i] == tomb[j]){
                printf("match\n");
                break;
            }
        }
    }
    return 0;
}
