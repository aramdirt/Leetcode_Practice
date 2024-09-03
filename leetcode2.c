/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (!l1)
        return l2;

    if (!l2)
        return l1;

    struct ListNode *head = l1;
    struct ListNode *tmp;
    int flag = 0;

    while (l1 && l2)
    {
        if (flag)
        {
            l1->val += 1;
            flag = 0;
        }

        l1->val += l2->val;

        if (l1->val >= 10)
        {
            l1->val -= 10;
            flag = 1;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1)
    {
        if (flag)
        {
            l1->val += 1;
            flag = 0;
        }

        if (l1->val >= 10)
        {
            l1->val -= 10;
            flag = 1;
        }

        tmp = l1;
        l1 = l1->next;
    }

    if (flag)
    {
        struct ListNode *node1 = malloc(sizeof(struct ListNode));
        node1->val = 1;
        node1->next = NULL;
        tmp->next = node1;
        flag = 0;
    }

    l1 = l2;
    while (l2)
    {
        if (flag)
        {
            l2->val += 1;
            flag = 0;
        }

        if (l2->val >= 10)
        {
            l2->val -= 10;
            flag = 1;
        }

        l2 = l2->next;
    }

    if (flag)
    {
        struct ListNode *node2 = malloc(sizeof(struct ListNode));
        node2->val = 1;
        node2->next = NULL;
        tmp->next = node2;
        flag = 0;
    }

    return head;
}