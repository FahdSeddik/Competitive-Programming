class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> cnts(nums.size()+1);
        for(auto x : mp){
            cnts[x.second].push_back(x.first);
        }
        vector<int> res(k);
        int i=0;
        for(int j=cnts.size()-1;j>=0;j--){
            if(i>=k)break;
            if(!cnts[j].size())continue;
            for(int l=0;l<cnts[j].size();l++){
                res[i]=cnts[j][l];
                i++;
                if(i>=k)break;
            }
        }
        return res;
    }
};