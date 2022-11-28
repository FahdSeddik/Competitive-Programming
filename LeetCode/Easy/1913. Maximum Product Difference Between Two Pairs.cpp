class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int min1=INT_MAX,min2=INT_MAX,max1=INT_MIN,max2=INT_MIN;
        for(auto i : nums){
            if(i<min1)min2=min1,min1=i;
            else if(i<min2)min2=i;
            if(i>max1)max2=max1,max1=i;
            else if(i>max2)max2=i;
        }
        return max1*max2-min1*min2;
    }
};