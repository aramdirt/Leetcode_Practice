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

    while (*ptr && (*ptr)->next)
    {
        if ((*ptr)->val == (*ptr)->next->val)
        {
            freenode = *ptr;
            *ptr = (*ptr)->next;
            free(freenode);
        }
        else
            ptr = &(*ptr)->next;
    }
    return head;
}