#include <stdio.h>

int main(void) {
    double a;
    double s;
    double buf[30] = {0, };

    for (;;) {
        fprintf(stderr, "点数を入力して下さい");
        // if (scanf("%lf", &a)==EOF) {
        //     break;
        // }
        if ( a >= 90 && a <= 100 ) {
            printf("%f\n", a);
            double s++;
        }
        else if ( a >= 85 && a <= 89 ) {
            printf("3.5\n");
            double a++;
        }
        else if ( a >= 80 && a <= 84 ) {
            printf("3.0\n");
            double b++;
        }
        // else if ( a >= 75 && a <= 79 ) {
        //     printf("2.5\n");
        //     double c++;
        // }
        // else if ( a >= 70 && a <= 74 ) {
        //     printf("2.0\n");
        //     double d++;
        // }
        // else if ( a >= 65 && a <= 69 ) {
        //     printf("1.5\n");
        //     double e++;
        // }
        // else if ( a >= 60 && a <= 64 ) {
        //     printf("1.0\n");
        //     double f++;
        }
    }
}