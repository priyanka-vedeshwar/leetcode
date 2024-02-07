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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* First = nullptr;
        ListNode* Cur = head;
        ListNode* Next = new ListNode();
        while(Cur != nullptr){
            Next = Cur->next;
            Cur->next = First;
            First = Cur;
            Cur = Next;
        }
        head = First;
        return head;
    }
};