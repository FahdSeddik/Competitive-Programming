class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return {};
        if(n==1)return {to_string(nums[0])};
        vector<string> ans;
        string temp = to_string(nums[0]);
        int last=nums[0],len=1;
        for(int i=1;i<n;i++){
            if(last+1==nums[i])len++,last=nums[i];
            else{
                if(len!=1){
                    temp+="->"+to_string(last);
                }
                len=1,last=nums[i];
                ans.push_back(temp);
                temp=to_string(nums[i]);
            }
        }
        if(len!=1)temp+="->"+to_string(last);
        ans.push_back(temp);
        return ans;
    }
};