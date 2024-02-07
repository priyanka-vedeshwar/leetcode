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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }
        if(list1->val > list2->val){
            auto temp = list2;
            list2 = list1;
            list1 = temp;
        }
        ListNode *l1 = list1;
        ListNode *l2 = list2;
        while(l1->next != nullptr && l2 != nullptr){
            if(l2->val >= l1->val && l2->val < l1->next->val){
                ListNode *temp = l2->next;
                l2->next=l1->next;
                l1->next = l2 ;
                l2 = temp;
            }
            l1 = l1->next;
        }
        if(l2 != nullptr){
            l1->next = l2;
       }
       return list1;
    }
};