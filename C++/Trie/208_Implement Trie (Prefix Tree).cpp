#include<string>
struct TrieNode{
    vector<TrieNode*> children{vector<TrieNode*>(26)};
    bool end; 
};

class Trie {
    TrieNode* head;    
public:
    Trie() {
        head = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp = this->head;
        for (auto w : word)
        {
            int index = (int)w - 'a';
            if (temp->children[index]==nullptr)
                temp->children[index] = new TrieNode();
            temp = temp->children[index]; 
        }
        temp->end = true;
    }
    
    bool search(string word) {
        TrieNode *temp = this->head;
        if (temp == nullptr)
            return false;
        for (auto w : word)
        {
            int index = (int)w - 'a';
            if (temp->children[index] == nullptr)
                return false;
            temp = temp->children[index];
        }
        return temp->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp = this->head;
        if (temp == nullptr)
            return false;
        for (auto w : prefix)
        {
            int index = (int)w - 'a';
            if(temp->children[index] == nullptr)
                return false;
            temp = temp->children[index];
        }
        return true;    
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */