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
    int gcd(int val1, int val2)
    {
        int gcd;
        if (val2 < val1)
        {
            int temp = val1;
            val1 = val2;
            val2 = temp;
        }
        for (int i = 1; i <= val1; i++)
            if ((val1 % i == 0) && (val2 % i == 0))
                gcd = i;
        return gcd;
    }

public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *first = head, *next = head->next;
        while (next != NULL)
        {
            ListNode *temp = new ListNode(gcd(first->val, next->val), next);
            first->next = temp;
            first = next;
            next = next->next;
        }
        return head;
    }
};
