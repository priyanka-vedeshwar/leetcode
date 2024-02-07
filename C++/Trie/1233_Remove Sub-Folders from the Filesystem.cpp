
struct TrieNode{
    map< string, TrieNode* > children;
    bool end;
};

class Trie{
    TrieNode *head;
    public:
        Trie()
        {
            head = new TrieNode();
        }

        string appendStr(string str){
        string res{"/"};
        int i =0;
        for (; i<str.size()-1;i++){
            res+=str[i];
            res+="/";
        }
        res += str[i];
        return res;
        }
        bool insert(vector<string> word)
        {
            TrieNode *temp = this->head;
            for (auto w : word)
            {
                if (temp->children[w] == nullptr)
                    temp->children[w] = new TrieNode();
                temp = temp->children[w];
                if (temp->end)
                {
                    return false;
                } 
            }
            temp->end = true;
            return true;
        }
};

class Solution {
    Trie *t;
public:
    Solution()
    {
        t = new Trie();
    }
    vector<string> splitStr(string str){
        string temp{};
        vector<string> res{};
        for(int i=1;i<str.size();i++){
            if(str[i]=='/'){
                res.push_back(temp);
                temp = "";
                continue;
            }
        temp += str[i];
        }
        res.push_back(temp);
        return res;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie head{};
        vector<string> res{};
        sort(folder.begin(),folder.end());
        for (auto folders : folder)
        {
            if (head.insert(splitStr(folders))){
                res.push_back(folders);
            }
        }
        return res;
    }
};