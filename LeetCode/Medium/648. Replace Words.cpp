typedef struct Node {
    vector<Node*> children;
    bool isWord = false;
} Node;
class Trie {
    Node* root=nullptr;
    public:
    void insert(const string& word){
        if(!root)root=new Node(), root->children.resize(26);
        Node* cur = root;
        for(char c : word){
            if(!cur->children[c-'a']) cur->children[c-'a'] = new Node(), cur->children[c-'a']->children.resize(26);
            else if (cur->children[c-'a']->isWord)return;
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
    }
    string getMatch(const string& word){
        Node* cur = root;
        string ans="";
        for(char c : word){
            ans+=c;
            if(!cur->children[c-'a'])return word;
            if(cur->children[c-'a']->isWord)return ans;
            cur = cur->children[c-'a'];
        }
        return cur && cur->isWord ? ans:word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie tree;
        for(auto& w : dictionary)tree.insert(w);
        string ans="", word="";
        for(char c : sentence){
            if(c==' '){
                ans+=tree.getMatch(word)+" ";
                word="";
                continue;
            }
            word+=c;
        }
        ans+=tree.getMatch(word);
        return ans;
    }
};