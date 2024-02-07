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
    int pairSum(ListNode* head) {
        vector<int> nums{};
        while(head != nullptr){
            nums.push_back(head->val);
            head = head->next;
        }
        int beg =0,end=nums.size()-1,maxSum=nums[0];
        while(beg<end){
            int sum = nums[beg] + nums[end];
            if(sum > maxSum)
                maxSum = sum;
            beg++;
            end--;
        }
        return maxSum;
    }
};