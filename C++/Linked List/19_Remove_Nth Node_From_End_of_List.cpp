/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // find nth Node from the end
        ListNode *dummy = new ListNode(0, head);
        ListNode *first = dummy, *second = dummy;
        // traverse first pointer to n+1 so that distance between first and second is n
        // nodes apart
        for (int i = 1; i <= n + 1; i++)
        {
            first = first->next;
        }
        // Move first to the end, maintaining the gap
        while (first != NULL)
        {
            first = first->next;
            second = second->next;
        }
        // remove nth node(second->next)
        second->next = second->next->next;
        return dummy->next;
    }
};
