class Solution {
    int btmask(string& s){
        int ans=0;
        for(char c:s){
            const int msk = 1 <<(c-'a');
            if(ans&msk)return -1;
            ans|=msk;
        }
        return ans;
    }
public:
    int maxLength(vector<string>& arr) {
        vector<int> bitmasks;
        for(string s: arr){
            int mask = btmask(s);
            if(mask!=-1)bitmasks.push_back(mask);
        }
        vector<int> all;
        for(auto b: bitmasks){
            int sz = all.size();
            for(int i=0;i<sz;i++){
                if(!(b & all[i])) all.push_back(b | all[i]);
            }
            all.push_back(b);
        }
        
        int res=0;
        for(auto c : all){
            res = max(res, __builtin_popcount(c));
        }
        return res;
    }
};