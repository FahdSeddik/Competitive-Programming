class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101]={0};
        for(int v : nums)freq[v]++;
        int mx=0;
        for(int v : freq)if(v>mx)mx=v;
        int ans=0;
        for(int v : freq)if(v==mx)ans+=v;
        return ans;
    }
};