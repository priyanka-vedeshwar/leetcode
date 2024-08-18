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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        int count = 0;
        ListNode *temp = list1;
        ListNode *start;
        while (temp != NULL && count <= b)
        {
            if (count == a - 1)
                start = temp;
            temp = temp->next;
            count++;
        }
        start->next = list2;
        while (list2->next != NULL)
            list2 = list2->next;
        list2->next = temp;
        return list1;
    }
};
