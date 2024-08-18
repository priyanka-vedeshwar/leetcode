/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *first = head, *next = head;
        while (next != NULL && next->next != NULL)
        {
            head = head->next;
            next = next->next->next;
            if (head == next)
                return true;
        }
        return false;
    }
};
