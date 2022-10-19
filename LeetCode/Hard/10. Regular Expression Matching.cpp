struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
class Solution {
    unordered_map<pair<int, int>, bool, hash_pair> m;
    bool dfs(string& s,string& p,int i,int j){
        if(m.count({i,j}))return m[{i,j}];
        if(i>=s.size() && j>=p.size())return true;
        if(j>=p.size())return false;
        bool match = i<s.size() && (s[i]==p[j] || p[j]=='.');
        if(j<p.size()-1 && p[j+1]=='*')//either not use or use
            return m[{i,j}] = (dfs(s,p,i,j+2) || (match && dfs(s,p,i+1,j)));
        if(match)
            return m[{i,j}] = dfs(s,p,i+1,j+1);
        return m[{i,j}] = false;
    }
public:
    bool isMatch(string s, string p) {
        return dfs(s,p,0,0);
    }
};