class Solution {
public:
    int mn=INT_MAX;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {        
        unordered_set<string> wrds;
        for(const auto& w: words){
            wrds.insert(w);
            mn = min(mn,(int)w.size());
        }
        vector<string> ans;
        for(const auto& w: words){
            if(check(wrds,w))ans.push_back(w);
        }
        return ans;
    }
    bool check(unordered_set<string>& wrds,string w){
        int n=w.size();
        if(n==mn)return false;
        for(int i=mn;i<=n-mn;i++){
            string prefix=w.substr(0,i);
            string suffix=w.substr(i,n-i);
            if(wrds.count(prefix) && (wrds.count(suffix) || check(wrds,suffix))){
                wrds.insert(suffix);
                return true;
            }
        }
        return false;
    }
};