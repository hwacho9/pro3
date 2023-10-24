#include <stdio.h>

int main(void) {
    int i;
    int score;
    double total = 0, ave;
    
    int count = 0;

    for (;; ){
        if ( scanf("%d", &score) == EOF ) { break; }
        if ( score >= 90 && score <= 100 ) {
            printf("4.0\n");
            total += 4.0;
        }
        else if ( score >= 85 && score <= 89 ) {
            printf("3.5\n");
            total += 3.5;
        } 
        else if ( score >= 80 && score <= 84 ) {
            printf("3.0\n");
            total += 3.0;
        } 
        else if ( score >= 75 && score <= 79 ) {
            printf("2.5\n");
            total += 2.5;
        } 
        else if ( score >= 70 && score <= 74 ) {
            printf("2.0\n");
            total += 2.0;
        } 
        else if ( score >= 65 && score <= 69 ) {
            printf("1.5\n");
            total += 1.5;
        } 
        else if ( score >= 60 && score <= 64 ) {
            printf("1.0\n");
            total += 1.0;
        } 
        else if ( score >= 0 && score <= 59 ) {
            printf("0.0\n");
        }   

            count ++;
    }
        ave = total / count;
        printf("%.3f\n", ave);

    return 0;

}