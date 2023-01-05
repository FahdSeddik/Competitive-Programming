class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        // -2 -2 -1 0 0 1 2
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int st=j+1,en=n-1;
                while(st<en){
                    long long sum = (long long)nums[i]+(long long)nums[j]+(long long)nums[st]+(long long)nums[en];
                    if(sum==target){
                        vector<int> candid{nums[i],nums[j],nums[st],nums[en]};
                        ans.push_back(candid);
                        while(st < en && nums[st] == candid[2]) st++;
                        while(st < en && nums[en] == candid[3]) en--;
                    }
                    else if(sum<target)st++;
                    else en--;
                }
                while(j + 1 < n && nums[j + 1] == nums[j]) j++;
            }
            while(i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
        return ans;
    }
    
};