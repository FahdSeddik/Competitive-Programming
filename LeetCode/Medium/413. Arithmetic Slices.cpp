class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        unordered_map<int,int> mp;
        int diff=nums[0]-nums[1],len=2;
        for(int i=1;i<n-1;i++){
            if(nums[i]-nums[i+1]==diff){
                len++;
            }else{
                if(len>2)mp[len-2]++;
                len=2;
                diff = nums[i]-nums[i+1];
            }
        }
        if(len>2)mp[len-2]++;
        int ans=0;
        for(const auto& x : mp){
            ans+= x.second*(x.first*(x.first+1)/2);
            cout<<x.second<<" "<<x.first<<"\n";
        }
        return ans;
    }
};