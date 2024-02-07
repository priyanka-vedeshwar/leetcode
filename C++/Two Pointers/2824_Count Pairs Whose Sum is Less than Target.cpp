class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        //sort
        sort(nums.begin(),nums.end());
        //method 1
        //Binary search to get other number such that nums[i]+oN = target
        //count pairs

        //method 2
        //two pointers
        int beg = 0, end = nums.size()-1,count=0;
        while(beg <= end){
            int sum = nums[beg] + nums[end];
            if(sum >= target)
                end--;
            else{
                count += end-beg;
                beg++;
            }
        }
        return count;   
    }
};