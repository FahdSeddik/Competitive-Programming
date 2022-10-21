class Solution {
    
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;//index,height
        int mx=0;
        for(int i=0;i<heights.size();i++){
            int start = i;
            while(!st.empty() && st.top().second > heights[i]){
                auto x = st.top();st.pop();
                mx = max(mx,x.second * (i-x.first));
                start = x.first;
            }
            st.push({start,heights[i]});
        }
        while(!st.empty()){
            auto v = st.top();st.pop();
            mx = max(mx, int(v.second* (heights.size() - v.first)));
        }
        return mx;
    }
};