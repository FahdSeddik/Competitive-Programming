class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int ans=0,cnt=0,i=0;
        for(const auto& f : fruits){
            mp[f]++,cnt++;
            while(mp.size()>2){
                --mp[fruits[i]];
                if(mp[fruits[i]]==0)mp.erase(fruits[i]);
                i++;
            }
            ans=max(ans,cnt-i);
        }
        return ans;
    }
};