class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)if(nums[i]<0)nums[i]=0;

        for(int i=0;i<n;i++){
            int j = abs(nums[i])-1;
            if(j<n && j>=0){
                if(nums[j]==0)nums[j]=-(n+1);
                else if(nums[j]>0)nums[j]=-nums[j];
            }
        }
        for(int i=1;i<=n;i++){
            if(nums[i-1]>=0)return i;
        }
        return n+1;
    }
};