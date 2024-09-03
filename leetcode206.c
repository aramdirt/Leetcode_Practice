/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *pre = NULL;
    struct ListNode *tmp;

    while(head)
    {
        tmp = head;
        head = head->next;
        tmp->next = pre;
        pre = tmp;
    }

    return pre;
}