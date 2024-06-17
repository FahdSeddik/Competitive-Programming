class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> freq(1001);
        for(int v : nums)freq[v]++;
        partial_sum(freq.rbegin(),freq.rend(),freq.rbegin());
        for(int i=nums.size();i>=0;i--)if(freq[i]==i)return i;
        return -1;
    }
};