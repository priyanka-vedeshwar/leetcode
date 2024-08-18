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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        ListNode *cur = head;
        ListNode *next = head;
        ListNode *prev = new ListNode(0, head);
        while (next != nullptr && next->next != nullptr)
        {
            prev = prev->next;
            cur = cur->next;
            next = next->next->next;
        }
        prev->next = cur->next;
        return head;
    }
};
