class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        unordered_set<char> s;
        s.insert('a'),s.insert('e'),s.insert('i'),s.insert('o'),s.insert('u');
        vector<int> sum(n+1);
        for(int i=0;i<n;i++){
            int m = words[i].size();
            sum[i+1]=sum[i]+ (s.count(words[i][m-1]) && s.count(words[i][0]));
        }
        vector<int> ans;
        for(const auto& v : queries){
            ans.push_back(sum[v[1]+1]-sum[v[0]]);
        }
        return ans;
    }
};