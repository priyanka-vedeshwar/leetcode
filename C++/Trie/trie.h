#ifndef __TRIE__
#define __TRIE__

#include <map>
using namespace std;

namespace Trie
{
    struct trie
    {
        map<char, trie *> children;
        bool end;
    };
    void Insert(trie *head, string word)
    {
        trie *temp = head;
        for (char c : word)
        {
            if (temp->children[c] == nullptr)
            {
                temp->children[c] = new trie();
            }
            temp = temp->children[c];
        }
        temp->end = true;
    }
    bool searchWord(trie *head, string word)
    {
        if (head == NULL)
            return false;
        trie *temp = head;
        for (char c : word)
        {
            if (temp->children[c] == NULL)
                return false;
            temp = temp->children[c];
        }
        return temp->end;
    }
    vector<string> &DFS(trie *head, vector<string> &res, string &str)
    {
        if (head->end)
        {
            res.push_back(str);
            return res;
        }
        for (auto [c, next] : head->children)
        {
            str.push_back(c);
            DFS(next, res, str);
            str.pop_back();
        }
        return res;
    }
    vector<string> &AllWords(trie *head, vector<string> &res, string &str)
    {
        if (head == NULL)
            return res;
        return DFS(head, res, str);
    }
    vector<string> &AllPrefix(trie *head, vector<string> &res, string str, string prefix)
    {
        if (head == NULL)
            return res;
        for (char c : prefix)
        {
            if (head->children[c] == NULL)
                return res;
            head = head->children[c];
        }
        return DFS(head, res, str);
    }
};
#endif