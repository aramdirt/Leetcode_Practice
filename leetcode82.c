/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *freenode = NULL;
    struct ListNode **ptr = &head;
    int tmp;

    while (*ptr && (*ptr)->next)
    {
        if ((*ptr)->val == (*ptr)->next->val)
        {
            tmp = (*ptr)->val;
            while ((*ptr)->val == tmp)
            {
                freenode = *ptr;
                *ptr = (*ptr)->next;
                free(freenode);
            }
        }
        else
            ptr = &(*ptr)->next;
    }
    return head;
}

#if 0
struct ListNode* deleteDuplicates(struct ListNode* head){
    int val = 0;
    struct ListNode **ptr = &head;
    struct ListNode *free_node;

    while (*ptr && (*ptr)->next)
    {
        if ((*ptr)->val == (*ptr)->next->val)
        {
            val = (*ptr)->val;
            while ((*ptr)->val == val)
            {
                free_node = *ptr;
                *ptr = (*ptr)->next;
                free(free_node);

                if (!(*ptr))
                    break;
            }
            continue;
        }
        ptr = &(*ptr)->next;
    }
    return head;
}
#endif
