/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (!head || !head->next)
        return false;

    struct ListNode *fast = head->next->next;
    struct ListNode *slow = head->next;

    while (fast != slow)
    {
        if (!fast || !fast->next || !slow)
            return NULL;

        fast = fast->next->next;
        slow = slow->next;
    }

    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}