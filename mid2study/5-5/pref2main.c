#include <stdlib.h>
#include "pref.h"

int main(void)
{
    pref_t *p[3];

    p[0] = pref_new("Tokyo", 2187.65, 12988797);
    p[1] = pref_new("Osaka", 1898.01, 8840372);
    p[2] = pref_new("Hyogo", 8395.89, 5599359);

    pref_print(a);
    pref_print(b);
    pref_print(c);

    free(a);
    free(b);
    free(c);
    a = NULL;
    b = NULL;
    c = NULL;

    return 0;
}