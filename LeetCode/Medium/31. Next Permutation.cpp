class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int id=-1;
        for(int i=n-2;i>=0;i--)if(nums[i]<nums[i+1]){
            id=i;break;
        }
        if(id==-1)reverse(nums.begin(),nums.end());
        else{
            int j;
            for(j=n-1;j>id;j--)if(nums[id]<nums[j])break;
            swap(nums[j],nums[id]);
            reverse(nums.begin()+id+1,nums.end());
        }
    }
};