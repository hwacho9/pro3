#include <stdint.h>
#define A_LEN 31
#define B_LEN 31


int main(void) {
    int k, n, m;
    int a[A_LEN +1];
    int b[B_LEN +1];

    scanf("%d", &k);
    for ( int i = 0; i < k; i++ ) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &n);
    scanf("%d", &m);

    for ( int j = 0; j < m; j++) {
        for ( int l = 0; l < n; i++) {
            scanf("%d", &b[i])
        }

        int match = 0;
        for ( int i = 0; i <= n-k; i++ ) {
            for ( int x = 0; x < k; x++ ) {
                if ( b[i+x ] != a[x])
                {   
                    int match = 0;
                    break;
                }
            }
        }





    }

}