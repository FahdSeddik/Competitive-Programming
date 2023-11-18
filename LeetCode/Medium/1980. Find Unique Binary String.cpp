class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for(int i=0;i<nums.size();i++){
            ans+=nums[i][i]=='0' ? '1':'0';
        }
        return ans;
    }
};

static const int io = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return 373;
}();