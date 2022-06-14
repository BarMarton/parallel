#include <stdio.h>

int rekurziv_small(int tomb[], int i);
int min(int a, int b);
int rekurziv_large(int tomb[], int i);
int max(int a, int b);

int main() {
    int tomb[] = {3,2,3,4,2,3,12,3,12,3,1,3,4};
    int smallest = tomb[0];
    int largest = tomb[0];
    //iteratív
    for(int i = 0; i< sizeof(tomb)/sizeof(tomb[0]); i++){
        if(smallest > tomb[i]) smallest = tomb[i];
        if(largest < tomb[i]) largest = tomb[i];
    }
    printf("smallest: %d \nlargest: %d\n", smallest, largest);
    //rekurzív
    printf("smallest with recursion: %d\n", rekurziv_small(tomb, sizeof(tomb)/sizeof(tomb[0])));
    printf("largest with recursion: %d\n", rekurziv_large(tomb, sizeof(tomb)/sizeof(tomb[0])));

    return 0;
}

int rekurziv_small(int tomb[], int i){
    if (i == 1) return tomb[0];
    return min(tomb[i-1], rekurziv_small(tomb, i-1));

}
int min(int a, int b)
{
    return a>b?b:a ;
}
int rekurziv_large(int tomb[], int i)
{
    if (i == 1) return tomb[0];
    return max(tomb[i-1], rekurziv_large(tomb, i-1));
}
int max(int a, int b)
{
    return a>b?a:b ;
}

