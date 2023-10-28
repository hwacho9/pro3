#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dice3_distr(int n, int d1[], int d2[], int d3[], int c[]) {
    for (int i = 0; i < n; i++) {
        int s = d1[i] + d2[i] + d3[i];
        c[s]++;
    }
}

int main() {
    srand(time(0));

    int n = 100; // 시뮬레이션 횟수
    int d1[n], d2[n], d3[n]; // 주사위 결과를 저장할 배열
    int c[18] = {0}; // 각 합 s의 발생 횟수를 저장할 배열, 0에서 17까지의 합이 가능

    for (int i = 0; i < n; i++) {
        d1[i] = (rand() % 6) + 1;
        d2[i] = (rand() % 6) + 1;
        d3[i] = (rand() % 6) + 1;
    }

    dice3_distr(n, d1, d2, d3, c);

    // 합 s의 발생 횟수 출력
    for (int i = 0; i < 18; i++) {
        printf("합 %d: %d회\n", i, c[i]);
    }

    return 0;
}
