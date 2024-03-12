class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int freq[1001]={0};
        for(int v : nums1)freq[v]++;
        vector<int> ans;
        for(int v : nums2)if(freq[v])ans.push_back(v),freq[v]=0;
        return ans;
    }
};

static const int fastio = [](){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    return 0;
}();