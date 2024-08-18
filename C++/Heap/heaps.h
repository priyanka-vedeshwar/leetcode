#ifndef __HEAP__
#define __HEAP__

#include <iostream>

using namespace std;

namespace priorityQueue
{

    class heap
    {
        vector<int> nums;
        void swap(int &, int &);
        bool isParent(int);
        int getParentIndex(int);
        void heapifyUp(vector<int> &);
        bool hasLeftChild(int, int);
        bool hasRighChild(int, int);
        int leftChildIndex(int);
        int rightChildIndex(int);
        void heapifyDown(vector<int> &);

    public:
        heap()
        {
            this->nums = vector<int>();
        }
        void pool(int);
        int poll();
        void traverse();
    };

    void heap::swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    bool heap::isParent(int index)
    {
        if (index == 1 || index == 2)
        {
            return true;
        }
        if (floor((index - 1) / 2) > 0)
            return true;
        else
            return false;
    }
    int heap::getParentIndex(int index)
    {
        return (floor((index - 1) / 2));
    }
    void heap::heapifyUp(vector<int> &nums)
    {
        int index = nums.size() - 1;
        if (index == 0)
        {
            return;
        }
        while (isParent(index))
        {
            int parentIndex = getParentIndex(index);
            if (nums[index] < nums[parentIndex])
            {
                swap(nums[index], nums[parentIndex]);
            }
            index = getParentIndex(index);
        }
    }
    bool heap::hasLeftChild(int index, int size)
    {
        if ((2 * index + 1) <= size)
            return true;
        return false;
    }
    bool heap::hasRighChild(int index, int size)
    {
        if ((2 * index + 2) <= size)
            return true;
        return false;
    }
    int heap::leftChildIndex(int index)
    {
        return ((2 * index + 1));
    }
    int heap::rightChildIndex(int index)
    {
        return ((2 * index + 2));
    }
    void heap::heapifyDown(vector<int> &nums)
    {
        int index = 0;
        int size = nums.size();
        while (hasLeftChild(index, size))
        {
            int smallIndex = leftChildIndex(index);
            if (hasRighChild(index, size) && nums[rightChildIndex(index)] < nums[smallIndex])
            {
                smallIndex = rightChildIndex(index);
            }
            if (nums[index] < nums[smallIndex])
                break;
            else
            {
                swap(nums[index], nums[smallIndex]);
            }
            index = smallIndex;
        }
    }
    void heap ::traverse()
    {
        for (int i : this->nums)
        {
            cout << i << "\t";
        }
        cout << "\n";
    }
    void heap::pool(int val)
    {
        this->nums.push_back(val);
        heapifyUp(this->nums);
        return;
    }
    int heap::poll()
    {
        int size = this->nums.size() - 1;
        if (size == 0)
        {
            return 0;
        }
        if (size == 1)
        {
            return this->nums[0];
        }
        int item = this->nums[0];
        this->nums[0] = this->nums[this->nums.size() - 1];
        this->nums.erase(this->nums.end() - 1);
        heapifyDown(this->nums);
        return item;
    }
};
#endif