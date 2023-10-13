static const int fast_io = [](){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return 0;
}();


class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n=queries.size();
        vector<bool> ans(n);
        for(int i=0;i<n;i++){
            if(queries[i].size()<pattern.size())continue;
            int j=0,b=1;
            for(auto c : queries[i]){
                if(j<pattern.size() && c==pattern[j]){
                    j++;
                    continue;
                }
                if(c<='Z' && c>='A')b=0;
            }
            ans[i]=j==pattern.size() && b;
        }
        return ans;
    }
};