#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 128

int main(void)
{
    char lines[MAX_LINES + 1][MAX_LINE_LENGTH + 1];
    int line_count = 0;

    // ファイルから行を読み込む
    while (fgets(lines[line_count], MAX_LINE_LENGTH, stdin) != NULL)
    {
        line_count++;
    }

    // 行を逆順に出力
    for (int i = line_count - 1; i >= 0; i--)
    {
        printf("%s", lines[i]);
    }

    return 0;
}
