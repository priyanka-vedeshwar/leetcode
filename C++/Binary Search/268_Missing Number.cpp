class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int end = nums.size()-1;
        int beg = 0;
        int ans = end+1;
        while(beg <= end){
            int mid = (beg+end)/2;
            if(mid == nums[mid])
                beg = mid+1;
            else{
                ans = mid;
                end = mid-1;
            }
        }
        return ans;
    }
};