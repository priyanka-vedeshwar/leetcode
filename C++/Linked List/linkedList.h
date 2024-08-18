// Linked implementation;
// Other operations on linked list are covered as part of leetcode solutions

#ifndef LINKED_LIST
#define LINKED_LIST

namespace linked_list
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
        void addVal(ListNode *head, int val)
        {
            ListNode *newNode = new ListNode{val, nullptr};
            if (head == nullptr)
            {
                head = newNode;
            }
            ListNode *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        void traverse(ListNode *head)
        {
            if (head == nullptr)
            {
                std::cout << "No data added yet\n";
                return;
            }
            ListNode *temp = head;
            while (temp != nullptr)
            {
                std::cout << "Val : " << temp->val << "\t";
                temp = temp->next;
            }
            std::cout << "\n";
        }
        void delete(ListNode *head)
        {
            if (head == nullptr)
            {
                std::cout << "No data to be deleted\n";
            }
            ListNode *prev;
            ListNode *temp = head;
            while (temp->next != nullptr)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = nullptr;
            delete (temp);
            return;
        }
        void delByVal(ListNode *head, int val)
        {
            if (head == nullptr)
            {
                std::cout << "No data to be deleted\n";
            }
            ListNode *prev;
            ListNode *temp = head;
            while (temp->val != val)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            return;
        }
    };

};

#endif
