#include <stdio.h>

int main (void) {
    int i, n;

    fprintf(stderr, "n을 입력해주세요");
    scanf("%d" , &n);

    for ( i = 1; i<n; i++) {
        if ( i % 3 == 0 ) {
            printf("%d\n" , i);
        }
        else if ( i % 10 == 3 || ( i / 10 )% 10 == 3) {
            printf("%d\n", i );
        }
    }
}