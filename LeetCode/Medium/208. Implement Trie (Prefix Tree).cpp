
class TrieNode {
public:
    bool isComplete;
    TrieNode* children[26];
    TrieNode(){
        isComplete=false;
        memset(children,0,sizeof(children));
    }
    
};
class Trie {
    TrieNode* root;
public:

    Trie() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* ptr = root;
        for(char c : word){
            if(!ptr->children[c-'a'])ptr->children[c-'a']=new TrieNode();
            ptr = ptr->children[c-'a'];
        }
        ptr->isComplete=true;
    }
    
    bool search(string word) {
        TrieNode* ptr = root;
        for(char c : word){
            if(!ptr->children[c-'a'])return false;
            ptr=ptr->children[c-'a'];
        }
        return ptr->isComplete;
    }
    
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for(char c : prefix){
            if(!ptr->children[c-'a'])return false;
            ptr=ptr->children[c-'a'];
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