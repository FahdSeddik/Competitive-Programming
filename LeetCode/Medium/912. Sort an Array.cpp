class Solution {
public:
    void merge(vector<int>& nums,int p,int q,int r){
        vector<int> L(nums.begin()+p,nums.begin()+q+1),R(nums.begin()+q+1,nums.begin()+r+1);
        L.push_back(INT_MAX),R.push_back(INT_MAX);
        int i=0,j=0;
        while(p<=r){
            if(L[i]<=R[j]){
                nums[p++]=L[i++];
            }else nums[p++]=R[j++];
        }
    }
    void merge_sort(vector<int>& nums,int p,int r){
        if (p<r){
            int q = (p+r)/2;
            merge_sort(nums,p,q);
            merge_sort(nums,q+1,r);
            merge(nums,p,q,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums,0,nums.size()-1);
        return nums;
    }
};