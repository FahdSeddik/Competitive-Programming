class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int cand1=0,cand2=1,cnt1=0,cnt2=0;
        for(auto v : nums){
            if(v==cand1)cnt1++;
            else if(v==cand2)cnt2++;
            else if(cnt1==0)cand1=v,cnt1=1;
            else if(cnt2==0)cand2=v,cnt2=1;
            else cnt1--,cnt2--;
        }
        cnt1=0,cnt2=0;
        for(auto v : nums){
            if(v==cand1)cnt1++;
            else if(v==cand2)cnt2++;
        }
        if(cnt1>nums.size()/3)ans.push_back(cand1);
        if(cnt2>nums.size()/3)ans.push_back(cand2);
        return ans;
    }
};