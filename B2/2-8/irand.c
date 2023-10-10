#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int irand(int, int);
// aからbまでの整数の乱数を生成する関数
int irand(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main() {
    srand(time(NULL)); // 乱数のシードを設定

    int a, b, n;
    int i;

    printf("a, b, nを入力: ");
    scanf("%d %d %d", &a, &b, &n);


    int count[10] = {0}; // 各数の生成回数を格納する配列

    for (int i = 0; i < n; i++) {
        int r = irand(a, b);
        printf("%d ", r);
        count[r - a]++; // 生成された数の回数をカウント
    }

    printf("\n");

    for (int i = a; i <= b; i++) {
        printf("%d: %d\n", i, count[i - a]);
    }

    return 0;
}
