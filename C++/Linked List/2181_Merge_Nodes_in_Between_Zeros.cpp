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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *first = head;
        ListNode *next = head->next;
        ListNode *res = new ListNode();
        int sum = 0;
        while (next != NULL)
        {
            if (next->val != 0)
            {
                sum += next->val;
            }
            if (next->val == 0)
            {
                first->val = sum;
                if (next->next == NULL)
                {
                    first->next = NULL;
                    break;
                }
                first->next = next;
                first = next;
                sum = 0;
            }
            next = next->next;
        }
        return head;
    }
};
