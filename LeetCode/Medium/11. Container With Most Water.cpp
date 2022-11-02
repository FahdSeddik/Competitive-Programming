class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        for(int i=0,j=height.size()-1;i<j;){
            int area = min(height[i],height[j])*(j-i);
            ans=max(area,ans);
            if(height[i]<=height[j])i++;
            else j--;
        }
        return ans;
    }
};