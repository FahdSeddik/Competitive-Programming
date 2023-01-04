class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        long long ans=0;
        for(auto i : tasks)mp[i]++;
        for(auto p : mp){
            int k = p.second;
            if(k==1)return -1;
            if(k%3==0)ans+=k/3;
            else ans+=k/3+1;
        }
        return ans;
    }
};