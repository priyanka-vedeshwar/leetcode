class Solution
{
    int searchNearest(vector<int> &row, int target)
    {
        int beg = 0, end = row.size() - 1;
        while (beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if (row[mid] == target)
                return mid;
            else if (row[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                beg = mid + 1;
            }
        }
        return end;
    }
    bool search(vector<int> &row, int target)
    {
        int beg = 0, end = row.size() - 1;
        while (beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if (row[mid] == target)
                return true;
            else if (row[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                beg = mid + 1;
            }
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        vector<int> rows;
        int index;
        for (vector<int> m : matrix)
        {
            rows.push_back(m[0]);
        }
        if (rows.size() == 1)
            index = 0;
        else
            index = searchNearest(rows, target);
        if (index >= 0 && index < rows.size())
            return search(matrix[index], target);
        return false;
    }
};
