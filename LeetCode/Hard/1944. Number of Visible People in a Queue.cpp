class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        if(n==1)return {0};
        vector<int> ans(n);
        stack<int> s;
        ans[n-1]=0;
        s.push(heights[n-1]);
        for(int i=n-2;i>=0;i--){
            // ans[i]= s.top()<heights[i] ? 0:1;
            while(!s.empty() && s.top()<heights[i])ans[i]++,s.pop();
            ans[i]+=!s.empty() ? 1:0;
            s.push(heights[i]);
        }
        return ans;
    }
};