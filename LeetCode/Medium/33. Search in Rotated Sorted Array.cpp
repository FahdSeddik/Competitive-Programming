class Solution {
public:
    int getMin(vector<int>& nums,int l,int r){
        if(r==0)return 0;
        if(nums[l]<nums[r])return 0;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]>nums[r])l=mid+1;
            else r=mid;
        }
        return l;
    }
    int search(vector<int>& nums, int target,int n=0,int mnidx=-1) {
        n=nums.size();
        //find split
        //check turning point
        //by binary search
        mnidx = getMin(nums,0,n-1);
        auto lb = lower_bound(nums.begin(),nums.begin()+mnidx,target);
        auto ub = lower_bound(nums.begin()+mnidx,nums.end(),target);
        if(ub!=nums.end() && *ub==target)return ub-nums.begin();
        if(lb!=nums.begin()+mnidx && *lb==target)return lb-nums.begin();
        return -1;
    }
};