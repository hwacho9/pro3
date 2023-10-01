#include <stdio.h>

int main(void) {
    int n;

    fprintf(stderr, "1から99の間の数字を入力してください");
    scanf("%d", &n);

    for ( int i = 1; i<=n; i++) {
        if ( i % 3 == 0 ) {
            printf("%d\n", i);
        } 
        else if ( i%10 == 3 || (i/10) % 10 == 3 ) {
            printf("%d\n", i);
        }
    }
}