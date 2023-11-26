class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size(),true);
        for(int i=0;i<l.size();i++){
            vector<int> temp(nums.begin()+l[i],nums.begin()+r[i]+1);
            sort(temp.begin(),temp.end());
            if(temp.size()<=2)continue;
            int diff = temp[1]-temp[0];
            for(int k=2;k<temp.size();k++){
                if(temp[k]-temp[k-1]!=diff){ans[i]=false;break;}
            }
        }
        return ans;
    }
};

static const int io = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return 0;
}();