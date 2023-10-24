#include <stdio.h>
#include <string.h>

#define W_LEN 31
#define W_FMT "%31s"

int main (void) {
    int i, n;
    char w[W_LEN+1];

    for (;;) {
        scanf(W_FMT, w);
        if( strcmp(w,"qq")==0) { break; }

        for ( i = 0; w[i] != '\0'; i++ ) {
            if ( w[i] != 'a' && w[i] !='i' && w[i] !='u' && w[i] !='e' && w[i] !='o') {
                w[i] = '*' ;
            } 
        }
        printf("%s\n",w);
    }

    return 0;
}