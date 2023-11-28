#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELEN 128

int main(void)
{
    char s[LINELEN + 1];
    char *line[100];
    int line_count = 0;
    while (fgets(s, LINELEN, stdin) != NULL)
    {
        line[line_count] = strdup(s);

        if (line[line_count] == NULL)
        {
            exit(1);
        }

        line_count++;
    }

    for (int i = line_count - 1; i >= 0; i--)
    {
        printf("%s", line[i]);
    }

    for (int i = 0; i < line_count; i++)
    {
        free(line[i]);
    }
    return 0;
}