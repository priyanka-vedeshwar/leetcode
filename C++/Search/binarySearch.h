#ifndef __SEARCH__
#define __SEARCH__

#include <vector>
using namespace std;

namespace search
{
    bool isPresent(const vector<int> &arr, int key, int beg, int end)
    {
        if (end >= beg)
        {
            int mid = beg + (end - beg) / 2;
            if (arr[mid] == key)
            {
                return true;
            }
            else if (arr[mid] > key)
            {
                return isPresent(arr, key, beg, mid - 1);
            }
            else
            {
                return isPresent(arr, key, mid + 1, end);
            }
        }
        return false;
    }

    int getIndex(const vector<int> &arr, int key, int beg, int end)
    {
        if (end >= beg)
        {
            int mid = beg + (end - beg) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }
            else if (arr[mid] > key)
            {
                return getIndex(arr, key, beg, mid - 1);
            }
            else
            {
                return getIndex(arr, key, mid + 1, end);
            }
        }
        return -1;
    }

    int ValueBelow(const vector<int> &arr, int key, int beg, int end)
    {
        if (beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if (arr[mid] == key)
            {
                if (mid > 0)
                {
                    return arr[mid - 1];
                }
                else if (mid == 0)
                {
                    return key;
                }
            }
            else if (arr[mid] > key)
            {
                return ValueBelow(arr, key, beg, mid - 1);
            }
            else
            {
                return ValueBelow(arr, key, mid + 1, end);
            }
        }
        return -1;
    }

    int valueAbove(const vector<int> &arr, int key, int beg, int end)
    {
        if (beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if (arr[mid] == key)
            {
                if (mid == arr.size() - 1)
                {
                    return key;
                }
                else
                {
                    return arr[mid + 1];
                }
            }
            else if (arr[mid] > key)
            {
                return valueAbove(arr, key, beg, mid - 1);
            }
            else
            {
                return valueAbove(arr, key, mid + 1, end);
            }
        }
        return -1;
    }

    int insertPos(const vector<int> &arr, int key, int beg, int end)
    {
        if (beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if (arr[mid] == key)
            {
                return insertPos(arr, key, beg, mid - 1);
            }
            else if (arr[mid] < key)
            {
                return insertPos(arr, key, mid + 1, end);
            }
            else
            {
                return insertPos(arr, key, beg, mid - 1);
            }
        }
        return end + 1;
    }
};
#endif