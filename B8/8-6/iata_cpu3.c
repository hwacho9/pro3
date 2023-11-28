#include <stdio.h>
#include <time.h>
#include "iata_db.h"

int main(void)
{
    clock_t clk_start, clk_end;
    db_t db;
    char key[KEY_LEN + 1];
    char *data;

    db_init(&db);
    db_load(&db);

    /* 空港コードを入力するとデータを出力; EOFまで繰り返し実行 */
    for (;;)
    {
        fprintf(stderr, "key = ");
        if (scanf(KEY_FMT, key) == EOF)
        {
            break;
        }
        clk_start = clock();
        for (int i = 0; i < 100000; i++)
        {
            data = db_hash_search(&db, key);
        }
        clk_end = clock();
        fprintf(stderr, "cpu = %9.6f [sec]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);
        if (data == NULL)
        {
            printf("NO RECORD\n");
        }
        else
        {
            printf("%s => %s\n", key, data);
        }
    }

    db_delete(&db);
    return 0;
}