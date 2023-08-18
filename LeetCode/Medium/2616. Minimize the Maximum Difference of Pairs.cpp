class Solution {
    int n;
public:
    int solve(vector<int>& nums,int d){
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]<=d)ans++,i++;
        }
        return ans;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0)return 0;
        sort(nums.begin(),nums.end());
        n = nums.size();
        int l=0,r=nums[n-1]-nums[0];
        while(l<r){
            int mid = l+(r-l)/2;
            int cnt = solve(nums,mid);
            if(cnt>=p)r=mid;
            else l=mid+1;            
        }
        return l;
    }
};