#include <stdio.h>
#define N 40

int main(void) {
    int i;
    for ( i =1; i<=N; i++) {
        if ( i%3 == 0) {
            printf("%d\n", i);
        }
        else if ( i%10 == 3 || (i /10) % 0 == 3 ) {
            printf("%d\n",i);
        }
    }
    printf("%d or %d or %d\n", 23%10, (63/10)%10, 6%3);
}
