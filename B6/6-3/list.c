#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static list_node_t *insert_node(list_node_t *p, int val);
static void remove_node(list_node_t *p);

list_node_t *create_node(int val)
/* 値 val を保持する新しい節点を作成し, その節点へのポインタを返す */
{
    list_node_t *new_node;
    new_node = (list_node_t *)malloc(sizeof(list_node_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "節点の割当てに失敗しました\n");
        exit(1);
    }
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

static list_node_t *insert_node(list_node_t *n, int val)
/* n の指す節点の直後に, 値 val を保持する新しい節点を挿入し,
  その節点へのポインタを返す */
{

    list_node_t *new_node = create_node(val);

    /* ノード n (nの指す節点) の直後に挿入 (この部分を埋めよ) */
    new_node->next = n->next;
    n->next = new_node;

    return new_node; // 挿入した節点へのポインタを返す
}

void list_print(list_node_t *head_p)
/* リストの内容を表示する */
{
    list_node_t *p = head_p->next; // 헤드 노드 다음의 첫 번째 노드부터 시작

    printf("[");
    for (; p != NULL; p = p->next)
    {
        printf(" %d ", p->val);
    }
    printf("]");

    printf("\n"); // 개행을 통해 출력을 마무리합니다.
}

static void remove_node(list_node_t *p)
/* p の指す節点の *直後* の節点を削除 */
{
    list_node_t *old = p->next;
    if (old == NULL)
    {
        fprintf(stderr, "Error: p->next = NULL\n");
        exit(1);
    }
    p->next = old->next;
    free(old);
    old = NULL;
}

list_node_t *list_insert(list_node_t *head_p, int val)
/* ヘッダが head_p のリストの先頭に値 val (の節点) を挿入する */
{
    list_node_t *p = insert_node(head_p, val);
    return p;
}

list_node_t *list_find(list_node_t *head_p, int val)
/* リスト中に値が val の節点を探す
   見つかればその節点のポインタを, なければ NULL を返す */
{
    list_node_t *p = head_p->next;

    for (; p != NULL; p = p->next)
    {
        if (p->val == val)
        {
            return p;
            exit(0);
        }
    }
    return NULL;
}

list_node_t *list_insert_uniq(list_node_t *n, int val)
{
    list_node_t *p = list_find(n, val);
    if (p == NULL)
    {
        list_insert(n, val);
    }
    return p;
}

// list_node_t *list_insert_delete_dup(list_node_t *head_p, int val)
// {
// }

// list_node_t *list_insert_delete_dup2(list_node_t *head_p, int val)
// {
// }

// list_node_t *list_sorted_insert_uniq(list_node_t *head_p, int val)
// {
// }

// list_node_t *list_sorted_insert_uniq2(list_node_t *head_p, int val)
// {
// }

// list_node_t *list_sorted_find(list_node_t *head_p, int val)
// {
// }

void list_delete(list_node_t *head_p)
{
    list_node_t *p = head_p->next;
    while (p != NULL)
    {
        list_node_t *next = p->next;
        free(p);
        p = next;
    }
    head_p->next = NULL;
}