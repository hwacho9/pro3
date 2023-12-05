#include <string.h>
#include <stdlib.h>

char *strdouble(char s[])
{
    int length = strlen(s);
    char *clone = NULL;

    clone = (char *)malloc(sizeof(char) * 2 * strlen(s) + 1);

    if (clone == NULL)
    {
        exit(1);
    }

    for (int i = 0; i < length; i++)
    {
        clone[i] = s[i];
        clone[i + length] = s[i];
    }
    clone[2 * length] = '\0';

    return clone;
}