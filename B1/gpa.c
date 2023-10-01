#include <stdio.h>

int main(void)
{
    int score;
    double s;
    int count = 0;

    for (;;)
    {
        fprintf(stderr, "点数を入力して下さい");
        if (scanf("%d", &score) == EOF)
        {
            break;
        }

        if (score >= 90 && score <= 100)
        {
            printf("4.0\n");
            s += 4.0;
        }
        else if (score >= 85 && score <= 89)
        {
            printf("3.5\n");
            s += 3.5;
        }
        else if (score >= 80 && score <= 84)
        {
            printf("3.0\n");
            s += 3.0;
        }
        else if (score >= 75 && score <= 79)
        {
            printf("2.5\n");
            s += 2.5;
        }
        else if (score >= 70 && score <= 74)
        {
            printf("2.0\n");
            s += 2.0;
        }
        else if (score >= 65 && score <= 69)
        {
            printf("1.5\n");
            s += 1.5;
        }
        else if (score >= 60 && score <= 64)
        {
            printf("1.0\n");
            s += 1.0;
        }
        else if (score >= 0 && score < 60)
        {
            printf("0.0\n");
            s += 0.0;
        }
        else
        {
            continue;
        }

        count++;
    }

    if (count > 0)
    {
        double average = s / count;
        printf("%.3lf\n", average);
    }
    else
    {
        fprintf(stderr, "データがありません。\n");
    }

    return 0;
}