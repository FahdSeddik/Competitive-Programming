class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int ans=0,cnt=0;
        for(int i=0,l=0;i<n;i++){
            mp[nums[i]]++;
            if(mp.size()>k){
                while(mp.size()>k){
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0)mp.erase(nums[l]);
                    l++;
                }
                cnt=0;
            } 
            if(mp.size()==k){
                while(mp[nums[l]]>1)cnt++,mp[nums[l]]--,l++;
                ans+=cnt+1;
            }
        }
        return ans;
    }
};