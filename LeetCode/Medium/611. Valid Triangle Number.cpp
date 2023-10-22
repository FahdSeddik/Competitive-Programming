class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int n=nums.size(),cnt=0;
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int a=nums[i],b=nums[j],c=nums[k];
                if(b+c>a)cnt+=k-j,j++;
                else k--;
            }
        }
        return cnt;
    }
};