#include <stdio.h>
#include <string.h>

#define len 31
#define W_FMT "%31s"

int main(void)
{
    int i;
    char w[len];

    for (;;)
    {
        fprintf(stderr, "英単語を入力して下さい (qq で終了): ");
        scanf(W_FMT, w);
        if (strcmp(w, "qq") == 0)
        {
            break;
        } /* 終了判定 */

        for (i = 0; w[i] != '\0'; i++)
        {
            if (w[i] != 'a' && w[i] != 'i' && w[i] != 'u' && w[i] != 'e' && w[i] != 'o')
            {
                w[i] = '*';
            }
        }

        printf("%s\n", w);
    }

    return 0;
}