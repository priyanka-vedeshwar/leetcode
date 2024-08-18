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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *first = dummy, *second = dummy;
        ListNode *tempHead = head;
        int size = 0;
        while (tempHead != NULL)
        {
            tempHead = tempHead->next;
            size++;
        }
        if (size == 0 || size == 1 || size == k)
            return head;
        if (k > size)
        {
            k = k % (size);
        }
        for (int i = 1; i <= k + 1 && first != NULL; i++)
        {
            first = first->next;
        }
        while (first != NULL)
        {
            first = first->next;
            second = second->next;
        }
        ListNode *temp = second;
        while (second->next != NULL)
        {
            second = second->next;
        }
        second->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
