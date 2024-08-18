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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *first = head;
        ListNode *second = head;
        while (second != NULL)
        {
            while (second != NULL && first->val == second->val)
            {
                second = second->next;
            }
            first->next = second;
            first = second;
            // second = second->next;
        }
        return head;
    }
};