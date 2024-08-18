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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *cur = head, *temp;
        ListNode *sentinel = new ListNode(0, head);
        ListNode *prev = sentinel;
        while (cur != NULL)
        {
            if (cur->val == val)
            {
                prev->next = cur->next;
                temp = cur;
            }
            else
                prev = cur;
            cur = cur->next;
        }
        return sentinel->next;
    }
};
