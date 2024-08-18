class Solution
{
public:
    int findFirst(vector<int> &nums, int target)
    {
        int beg = 0;
        int end = nums.size() - 1;
        int res = -1;
        while (beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] == target)
            {
                res = mid;
                end = mid - 1;
            }
            else if (nums[mid] > target)
                end = mid - 1;
            else
                beg = mid + 1;
        }
        return res;
    }
    int findLast(vector<int> &nums, int target)
    {
        int beg = 0;
        int end = nums.size() - 1;
        int res = -1;
        while (beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] == target)
            {
                res = mid;
                beg = mid + 1;
            }
            else if (nums[mid] > target)
                end = mid - 1;
            else
                beg = mid + 1;
        }
        return res;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res{};
        res.push_back(findFirst(nums, target));
        res.push_back(findLast(nums, target));
        return res;
    }
};
