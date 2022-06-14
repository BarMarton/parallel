#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#define MAX_LINE_LENGTH 1000
#define DAYS 13
int checkText(char location[], char word[]);

int main() {
    char emote1[] = "PagMan";

    struct timeval t1, t2, dt;
    gettimeofday(&t1, NULL);
    int emote1_counter = 0;
    for(int i = 1; i <= DAYS; i++){
        char c[2];
        sprintf(c, "%d", i);
        emote1_counter += checkText( c, emote1);
        //printf("%d\n", i);
    }


    gettimeofday(&t2, NULL);
    timersub(&t2, &t1, &dt);

    printf(emote1);
    printf(" count: %d\n", emote1_counter);

    printf("%ld.%06ld seconds\n", dt.tv_sec, dt.tv_usec);

    return 0;
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