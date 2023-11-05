#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

istack_t *istack_new(int size)
{
    istack_t *stack = (istack_t *)malloc(sizeof(istack_t));
    if (stack == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    stack->size = size;
    stack->sp = 0;
    stack->data = (int *)malloc(sizeof(int) * size);
    if (stack->data == NULL)
    {
        free(stack);
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    return stack;
}

void istack_delete(istack_t *s)
{
    if (s != NULL)
    {
        free(s->data);
        free(s);
    }
    else
    {
        // fprintf(stderr, "Stack is full. Cannot push.\n");
    }
}

void istack_push(istack_t *s, int d)
{
    if (istack_full(s))
    {
        // スタックが満杯の場合、サイズを2倍に拡張
        int new_size = s->size * 2;
        int *new_data = (int *)realloc(s->data, sizeof(int) * new_size);

        if (new_data == NULL)
        {
            // fprintf(stderr, "Memory allocation failed during resizing.\n");
            return;
        }

        s->data = new_data;
        s->size = new_size;
    }

    s->data[s->sp] = d;
    s->sp++;
}

void istack_pop(istack_t *s, int *d)
{
    if (istack_empty(s))
    {
        // スタックが空の場合、*d に 0 をセット
        *d = 0;
    }
    else
    {
        s->sp--;
        *d = s->data[s->sp];
    }
}

int istack_empty(istack_t *s)
{
    return (s->sp == 0) ? 1 : 0;
}

int istack_full(istack_t *s)
{
    return (s->sp == s->size) ? 1 : 0;
}