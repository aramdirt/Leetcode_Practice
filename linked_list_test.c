#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE     50
#define LIST_SIZE 10

typedef struct ListNode{
    struct ListNode *next;
    int val;
}node_t;

void print_list(node_t *head)
{
    for (node_t *cur = head; cur; cur = cur->next)
        printf("%d ", cur->val);

    printf("\n");
}

/* Add node */
void add_entry(node_t *head, int new_val)
{
    node_t **indirect = &head;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->val = new_val;
    new_node->next = NULL;

    while (*indirect)
        indirect = &(*indirect)->next;

    *indirect = new_node;
}

void add_entry_2(node_t *head, int new_val)
{
    node_t *node = head;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->val = new_val;
    new_node->next = NULL;

    while (node->next)
        node = node->next;

    node->next = new_node;
}

/* Find node */
node_t *find_entry(node_t *head, int find_val)
{
    node_t *cur = head;

    for (; cur && cur->val != find_val; cur = cur->next);

    return cur;
}

/* Remove node */
void remove_entry(node_t **head, node_t *entry)
{
    node_t **indirect = head;
    while (*indirect != entry)
        indirect = &(*indirect)->next;

    *indirect = (*indirect)->next;
    free(entry);
}

/* Remove list */
void remove_list(node_t *node)
{
    node_t *nxt = NULL;
    while (node)
    {
        nxt = node->next;
        free(node);
        node = nxt;
    }
}

/* Merge two lists */
node_t *mergeTwoLists(node_t *L1, node_t *L2)
{
    node_t *head = NULL;
    node_t **ptr = &head;
    for (node_t **node = NULL; L1 && L2; *node = (*node)->next)
    {
        node = (L1->val < L2->val) ? &L1 : &L2;
        *ptr = *node;
        ptr = &(*ptr)->next;
    }

    *ptr = (node_t *)((unsigned long int) L1 | (unsigned long int) L2);
    return head;
}

/* Merge K lists */
node_t *mergeKLists(node_t **list, int list_num)
{
    if (!list_num)
        return NULL;

    if (list_num == 1)
        return list[0];

    int i, j;
    while (list_num > 1)
    {
        for (i=0, j=list_num-1; i<j; i++, j--)
            list[i] = mergeTwoLists(list[i], list[j]);

        list_num = (list_num + 1)/2;
    }
    return list[0];
}

/* Merge sort list */
node_t *mergesort_list(node_t *head)
{
    if (!head || !head->next)
        return head;

    node_t *fast, *slow, *mid, *Left, *Right;
    slow = head;
    for (fast = head->next; fast && fast->next; fast = fast->next->next)
        slow = slow->next;

    mid = slow->next;
    slow->next = NULL;
    Left = mergesort_list(head);
    Right = mergesort_list(mid);

    return mergeTwoLists(Left, Right);
}

/* Reverse list */
node_t *reverse_list(node_t *head)
{
    node_t *last = NULL;
    node_t *node;
    while (head)
    {
        node = head->next;
        head->next = last;
        last = head;
        head = node;
    }
    return last;
}

int main(int argc, char const *argv[])
{
    int i;
    node_t *head = NULL;

    srand(time(NULL));

    for (i=0; i<LIST_SIZE; i++)
        add_entry(&head, rand()%RANGE);

    printf("Create random list:\n");
    print_list(head);

    head = mergesort_list(head);
    printf("Merge sort list:\n");
    print_list(head);

    head = reverse_list(head);
    printf("Reverse list:\n");
    print_list(head);

    remove_list(head);
    return 0;
}