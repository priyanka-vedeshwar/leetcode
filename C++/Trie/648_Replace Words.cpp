struct TrieNode{
    map<char, TrieNode*> children;
    bool end;
};

class Trie{
    TrieNode *head;
    public:
        Trie(){
            head = new TrieNode();
        }
        void insert(string Word){
            TrieNode *temp = this->head;
            for(auto w:Word){
                if(temp->children[w] == nullptr)
                    temp->children[w] = new TrieNode();
                temp = temp->children[w];
            }
            temp->end = true;
        }
        string replace(string Word){
            string Res{};
            TrieNode *temp = this->head;
            for(auto w:Word){
                if (temp->children[w] == nullptr ){
                    if(temp->end){
                        return Res;
                    }else{
                        return "";
                    }
                }
                temp = temp->children[w];
                Res.push_back(w);
                if (temp->end){
                    return Res;
                }
                
            }
            return Res;
        }
};
vector<string> split(string str, string delimiter)
{
    vector<string> v;
    if (!str.empty()) {
        int start = 0;
        do {
            // Find the index of occurrence
            int idx = str.find(delimiter, start);
            if (idx == string::npos) {
                break;
            }
 
            // If found add the substring till that
            // occurrence in the vector
            int length = idx - start;
            v.push_back(str.substr(start, length));
            start += (length + delimiter.size());
        } while (true);
        v.push_back(str.substr(start));
    }
 
    return v;
}
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> Words = split(sentence," ");
        Trie t{};
        string Res;
        for(auto dict : dictionary){
            t.insert(dict);
        }
        for(int i = 0; i< Words.size(); i++){
            string temp = t.replace(Words[i]);
            if (temp != ""){
                Res+=temp;
            }else{
                Res+=Words[i];
            }
            Res+=" ";
        }
        return Res.substr(0,Res.size()-1);
    }
};