class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                res.push_back(sum);
            }
        }
        const int M = 1e9 + 7;
        sort(res.begin(), res.end());
        long int sum = 0;
        for (int i = left - 1; i < right; i++)
        {
            sum += res[i];
            sum = sum % M;
        }
        return sum;
    }
};
