class Solution {
public:
    int NegativeCount(vector<int> &nums){
        int beg = 0;
        int end = nums.size()-1;
        while(beg<=end){
            int mid = beg+(end - beg)/2;
            if(nums[mid] < 0 )
                beg = mid+1;
            else
                end=mid-1;
        }
        return (end+1);
    }
    int maximumCount(vector<int>& nums) {
        int neg{},pos{},zCount{};
        for(auto num : nums){
            if (num ==0)
                zCount++;
        }
            neg = NegativeCount(nums);
            cout<<neg<<"\n";
            pos = nums.size()-neg-zCount;
        if(neg>pos)
            return neg;
        return pos;
    }
};