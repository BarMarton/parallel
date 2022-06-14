#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <omp.h>
#define MAX_LINE_LENGTH 1000
#define DAYS 13
int checkText(char location[], char word[]);
int parallelPart(char emote[]);

int main() {
    char emote1[] = "PagMan";
    struct timeval t1, t2, dt;

    gettimeofday(&t1, NULL);

    int counter = parallelPart(emote1);

    gettimeofday(&t2, NULL);
    timersub(&t2, &t1, &dt);

    printf(emote1);
    printf(" count: %d\n", counter);
    printf("%ld.%06ld seconds\n", dt.tv_sec, dt.tv_usec);

    return 0;
}
int parallelPart(char emote[]){
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
            for(int i = 1; i <= DAYS; i++){
                int thread_count = omp_get_num_threads();
                int ID = omp_get_thread_num();
                char c[2][thread_count];
                sprintf(c[ID], "%d", i);
                sum += checkText(c[ID], emote);
                //printf("%d\n", i);
            }
    return sum;
}
int checkText(char location[], char word[]){
    FILE    *textfile;
    textfile = fopen(location, "r");
    char    line[MAX_LINE_LENGTH];
    if(textfile == NULL)
        return 1;
    int count = 0;

    while(fgets(line, MAX_LINE_LENGTH, textfile)){
        if (strstr(line, word) != NULL){
            //printf(line);
            count++;
        }
    }
    fclose(textfile);
    return count;
}