class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for(int n : s){
            if(s.find(n-1)==s.end()){
                int len=0;
                while(s.find(n+len)!=s.end())len++;
                ans=max(ans,len);
            }
        }
        return ans;
    }
};