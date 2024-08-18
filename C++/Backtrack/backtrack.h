#ifndef __BACKTRACK__
#define __BACKTRACK__

using namespace std;

namespace backtrack
{
    void swap(vector<int> &arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    void allPermutation(vector<int> &arr, vector<vector<int>> &res, int l, int r)
    {
        if (l == r)
        {
            vector<int> temp{};
            for (int i = 0; i < arr.size(); i++)
            {
                temp.push_back(arr[i]);
            }
            res.push_back(temp);
            return;
        }
        for (int i = l; i < r; i++)
        {
            swap(arr, l, i);
            allPermutation(arr, res, l + 1, r);
            swap(arr, l, i);
        }
    }
};
#endif
