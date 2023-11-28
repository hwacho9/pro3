#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 126
#define SFMT "%126s"

char *strclone(char s[]);

int main(void)
{
    char s[SLEN + 1];
    char *s2 = NULL;

    for (;;)
    {
        fprintf(stderr, "s = ");
        if (scanf(SFMT, s) == EOF)
        {
            break;
        }
        s2 = strclone(s);
        printf("s2 = %s\n", s2);
        free(s2);
        s2 = NULL;
    }

    return 0;
}

char *strclone(char s[])
{
    char *clone = NULL;
    int i;
    int length = strlen(s);

    clone = (char *)malloc(sizeof(char) * length + 1);

    strcpy(clone, s);

    return clone;
}
