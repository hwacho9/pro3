#include <stdio.h>

#define LINELEN 128

int main(void)
{
    char s[LINELEN + 1];
    char *line[100];
    int line_count = 0;

    while (fgets(s, LINELEN, stdin) != NULL)
    {
        printf("%s", s);
    }
    return 0;
}