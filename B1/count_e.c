#include <stdio.h>
#include <string.h> /* strcmp 等の文字列関数使用時に必要 */

#define W_LEN 31     /* 文字列 w の最大文字数 */
#define W_FMT "%31s" /* 文字列 w を読み込むフォーマット */

int main(void)
{
    int i;
    int n_e;
    char w[W_LEN + 1];

    for (;;)
    {

        fprintf(stderr, "英単語を入力して下さい (END で終了): ");
        scanf(W_FMT, w);
        if (strcmp(w, "END") == 0)
        {
            break;
        } /* 終了判定 */

        n_e = 0;
        for (i = 0; w[i] != '\0'; i++)
        { /* 文字列走査の決まった書き方 */
            if (w[i] == 'e')
            {
                n_e++;
            }
        }
        printf("%d\n", n_e);
    }

    return 0;
}