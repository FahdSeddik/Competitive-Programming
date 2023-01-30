class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words,int i=0,int j=0) {
        unordered_map<string,int> dict,check;
        for(const auto& w : words)dict[w]++;
        int wsz = words[0].size(),cnt=words.size();
        vector<int> ans;
        for(i=0;i<=(int)s.size()-wsz*cnt;i++){
            check = dict;
            for(j=0;j<cnt;j++){
                string w = s.substr(i+j*wsz,wsz);
                if(check[w])check[w]--;
                else break;
            }
            if(j==cnt)ans.push_back(i);
        }
        return ans;
    }
};