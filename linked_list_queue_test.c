#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE     50
#define LIST_SIZE 10

typedef struct ListNode{
    struct ListNode *next;
    int val;
}node_t;

typedef struct QueueList {
    int size;
    node_t *head, *tail;
}queue_list_t;

void InitQueue(queue_list_t *queue_list)
{
    queue_list->size = 0;
    queue_list->head = NULL;
    queue_list->tail = NULL;
}

int QueueIsEmpty(queue_list_t *queue_list)
{
    return queue_list->head == NULL;
}

/* Add node */
void AddQueue(queue_list_t *queue_list, int val)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->val = val;
    tmp->next = NULL;

    if (!queue_list->head)
        queue_list->head = tmp;
    else
        queue_list->tail->next = tmp;

    queue_list->tail = tmp;
    queue_list->size++;
}

/* Delete node */
int DeleteQueue(queue_list_t *queue_list)
{
    node_t *tmp = queue_list->head;
    int ret = tmp->val;

    queue_list->head = queue_list->head->next;
    if (!queue_list->head)
    {
        queue_list->size = 0;
        queue_list->tail = NULL;
    }
    else
        queue_list->size--;

    free(tmp);
    return ret;
}

/* Insert node */
void InsertQueue(queue_list_t *queue_list, int val, int index)
{
    int cnt;
    node_t *tmp1, *tmp2;
    node_t *new = malloc(sizeof(node_t));
    new->val = val;
    new->next = NULL;

    if (index > queue_list->size)
    {
        queue_list->tail->next = new;
        queue_list->tail = new;
        queue_list->size++;
    }
    else
    {
        for (cnt = 0, tmp1 = queue_list->head; cnt != index; cnt++, tmp1 = tmp1->next);

        tmp2 = tmp1->next;
        tmp1->next = new;
        new->next = tmp2;
        queue_list->size++;
    }
}