class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int beg = 0;
        int end = nums.size() - 1;
        while (beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                beg = mid + 1;
        }
        return -1;
    }
    bool checkIfExist(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            int res = search(arr, arr[i] * 2);
            if (res != -1 && res != i)
                return true;
        }
        return false;
    }
};
