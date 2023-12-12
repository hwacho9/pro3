#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELEN 128

int main(void)
{
    char s[LINELEN + 1];
    char *line[100]; // 適切な行数に設定する (この例では最大100行)
    int line_count = 0;

    // 行ごとに文字列を読み込み、lineに格納する
    while (fgets(s, LINELEN, stdin) != NULL)
    {
        // 改行文字を削除してからコピー
        // s[strcspn(s, "\n")] = '\0';
        line[line_count] = strdup(s);

        if (line[line_count] == NULL)
        {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        line_count++;
    }

    // 逆順に出力
    for (int i = line_count - 1; i >= 0; i--)
    {
        printf("%s\n", line[i]);
    }

    // メモリの解放
    for (int i = 0; i < line_count; i++)
    {
        free(line[i]);
    }

    return 0;
}
