class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target/*,int a=0,int b=0*/) {
        /*auto it1 = lower_bound(nums.begin(),nums.end(),target);
        auto it2 = upper_bound(nums.begin(),nums.end(),target);
        if(it1==nums.end() ||*it1!=target)return {-1,-1};
        return {a = it1-nums.begin(),b = it2-nums.begin()-1};*/
        int id1=-1,n=nums.size(),l=0,r=n-1,mid;
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid]==target)id1=mid,r--;
            else if(nums[mid]>target)r=mid-1;
            else l=mid+1;
        }
        if(id1==-1)return {-1,-1};
        l=0,r=n-1;
        int id2=-1;
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid]==target)id2=mid,l++;
            else if(nums[mid]>target)r=mid-1;
            else l=mid+1;
        }
        return {id1,id2};
    }
};