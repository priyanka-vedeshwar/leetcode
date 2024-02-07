/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class HashSet{
    map<ListNode*,bool> hashSet;
    public:
        HashSet(){
            hashSet={};
        }
        void insert(ListNode *node){
            if(!this->hashSet[node]){
                this->hashSet[node]=true;
            }
        }
        bool check(ListNode *node){
            if(this->hashSet[node])
                return true;
            return false;
        }
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        HashSet hs{};
        while(headA != nullptr){
            hs.insert(headA);
            headA = headA->next;
        }
        while(headB != nullptr){
            if(hs.check(headB))
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};