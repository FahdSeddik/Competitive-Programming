class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int result=0;
        int lmax=0,rmax=0;
        while(l<=r){
            if(lmax<=rmax){
                result+=max(0,lmax-height[l]);
                lmax=max(lmax,height[l]);
                l++;
            }else{
                result+=max(0,rmax-height[r]);
                rmax=max(rmax,height[r]);
                r--;
            }
        }
        return result;
    }
};