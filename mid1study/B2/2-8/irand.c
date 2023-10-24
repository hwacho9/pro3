#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int irand( int a, int b) {
    return rand() % ( b - a + 1) + a;
}

int main() {
    srand(time(NULL));

    int a, b, n;
    int i;

    scanf("%d %d %d", &a, &b, &n);

    int count[100] = {0};

    for (int i = 0; i < n; i++) {
        int r = irand(a,b);
        printf("%d\n", r);
        count[r - a]++; // 生成された数の回数をカウント
    }

    printf("\n");

    for ( int i = a; i <= b; i++ ) {
        printf("%d: %d\n", i, count[i - a]);
    }



    return 0;
}