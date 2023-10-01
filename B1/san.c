#include <stdio.h>
#define N 40

int main(void) {
    int i;
    for ( i =1; i<=N; i++) {
        if ( i%3 == 0) {
            printf("%d\n", i);
        }
        else if ( i%10 == 3 || (i /10)%10 == 3 ) {
            printf("%d\n",i);
        }
    }
}
