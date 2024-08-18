class Solution
{
public:
    int BinarySearch(vector<int> &nums, int target, int index)
    {
        int beg = 0;
        int end = nums.size() - 1;
        while (beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] == target and mid != index)
                return mid + 1;
            else if (nums[mid] == target && mid == index)
                return mid + 2;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                beg = mid + 1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        /*vector<int>Res{};
        for(int i=0;i<numbers.size();i++){
            auto temp = BinarySearch(numbers,target-numbers[i],i);
            if(temp != -1){
                return vector<int>{i+1,temp};
            }
        }
        return Res;
        */
        vector<int> res{};
        int beg = 0, end = numbers.size() - 1;
        while (beg < end)
        {
            int sum = numbers[beg] + numbers[end];
            if (sum == target)
            {
                res.push_back(beg + 1);
                res.push_back(end + 1);
                return res;
            }
            else if (sum > target)
                end--;
            else
                beg++;
        }
        return res;
    }
};
