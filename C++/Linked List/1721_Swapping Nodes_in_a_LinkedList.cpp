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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *first = dummy, *sec = dummy;
        ListNode *temp;
        for (int i = 1; i <= k + 1; i++)
        {
            sec = sec->next;
            if (i == k)
            {
                temp = sec;
            }
        }
        while (sec != NULL)
        {
            sec = sec->next;
            first = first->next;
        }
        int tempVal = first->next->val;
        first->next->val = temp->val;
        temp->val = tempVal;
        return head;
    }
};
