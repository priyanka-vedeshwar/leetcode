class Solution
{
public:
    int NegativeCount(vector<int> &nums)
    {
        int beg = 0;
        int end = nums.size() - 1;
        while (beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] < 0)
                end = mid - 1;
            else
                beg = mid + 1;
        }
        return (nums.size() - beg);
    }
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        for (auto g : grid)
        {
            count += NegativeCount(g);
        }
        return count;
    }
};
