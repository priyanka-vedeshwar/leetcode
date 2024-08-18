class SeatManager
{
    vector<int> seats;

public:
    bool isParent(int index)
    {
        if (index == 1 || index == 2)
            return true;
        if (floor((index - 1) / 2) > 0)
            return true;
        else
            return false;
    }
    int parentIndex(int index)
    {
        return floor((index - 1) / 2);
    }
    void heapifyUp(vector<int> &nums)
    {
        int index = nums.size() - 1;
        if (index == 0)
        {
            return;
        }
        while (isParent(index))
        {
            if (nums[index] < nums[parentIndex(index)])
                swap(nums[index], nums[parentIndex(index)]);
            index = parentIndex(index);
        }
    }
    bool isRightChild(int index, int size)
    {
        if ((2 * index + 2) <= size)
            return true;
        return false;
    }
    bool isLeftChild(int index, int size)
    {
        if ((2 * index + 1) <= size)
            return true;
        return false;
    }
    int rightIndex(int index)
    {
        return (2 * index + 2);
    }
    int leftIndex(int index)
    {
        return (2 * index + 1);
    }
    void heapifyDown(vector<int> &nums)
    {
        int index = 0;
        int size = nums.size();
        while (isLeftChild(index, size))
        {
            int smallIndex = leftIndex(index);
            if (isRightChild(index, size) && nums[smallIndex] > nums[rightIndex(index)])
                smallIndex = rightIndex(index);
            if (nums[index] > nums[smallIndex])
                swap(nums[index], nums[smallIndex]);
            index = smallIndex;
        }
    }
    int poll(vector<int> &nums)
    {
        int num = nums[0];
        nums[0] = nums[nums.size() - 1];
        nums.erase(nums.end() - 1);
        heapifyDown(nums);
        return num;
    }

    void pool(vector<int> &nums, int i)
    {
        nums.push_back(i);
        heapifyUp(nums);
        return;
    }
    SeatManager(int n)
    {
        for (int i = 1; i <= n; i++)
            pool(seats, i);
    }
    int reserve()
    {
        int seat = poll(this->seats);
        return seat;
    }

    void unreserve(int seatNumber)
    {
        pool(this->seats, seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
