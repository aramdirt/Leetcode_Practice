#include <stdio.h>
#include <stdlib.h>

bool hasCycle(struct ListNode *head) {
    if (!head || !head->next)
        return false;

    struct ListNode *fast = head->next->next;
    struct ListNode *slow = head->next;

    while (fast != slow)
    {
        if (!fast || !fast->next || !slow)
            return false;

        fast = fast->next->next;
        slow = slow->next;
    }
    return true;
}