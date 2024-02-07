struct TrieNode{
    map< char,TrieNode* > children;
    bool end;
};

class Trie{
    TrieNode *head;
    public:
        Trie(){
            head = new TrieNode{};
        }
        void insert(string Word){
            TrieNode *temp = this->head;
            for (auto w : Word){
                if(temp->children[w] == nullptr)
                    temp->children[w] = new TrieNode();
                temp = temp->children[w]; 
            }
            temp->end = true;
        }
        string LongestCommonPrefix(){
            string Res{};
            TrieNode *temp = this->head;
            while(!temp->end && temp->children.size() == 1){
                for(auto t : temp->children){
                    temp = t.second;
                    Res += t.first;
                }
                
            }
        return Res;
        }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie root{};
        for(auto str : strs){
            root.insert(str);
        }
        string Res = root.LongestCommonPrefix();
        return Res;
    }
};