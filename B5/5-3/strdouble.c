#include <stdlib.h>
#include <string.h>

char *strdouble(char s[])
{
    int length = strlen(s);
    char *result = (char *)malloc(sizeof(char) * (2 * length + 1)); // 2倍の長さ + 1 (終端の '\0')

    if (result != NULL)
    {
        for (int i = 0; i < length; i++)
        {
            result[i] = s[i];
            result[i + length] = s[i]; // 2回繰り返す
        }
        result[2 * length] = '\0'; // 終端を追加
    }

    return result;
}
