class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0,n_2=nums.size()/2;
        for(int i=0;i<32;i++){
            int bit = 1<<i,cnt=0;
            for(const auto& v : nums)if(bit&v)cnt++;
            if(cnt>n_2)ans|=bit;
        }
        return ans;
    }
};