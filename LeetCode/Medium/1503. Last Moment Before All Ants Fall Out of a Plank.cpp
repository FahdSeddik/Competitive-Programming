class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0;
        if(left.size())ans=*max_element(left.begin(),left.end());
        for(int v : right){
            ans = max(ans,n-v);
        }
        return ans;
    }
};