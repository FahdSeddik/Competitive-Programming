class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int ans=0;
        vector<int> left(capacity.size());
        for(int i=0;i<capacity.size();i++){
            left[i]=capacity[i]-rocks[i];
        }
        sort(left.begin(),left.end());
        for(int i=0;i<left.size();i++){
            if(left[i]<=additionalRocks){
                ans++;
                additionalRocks-=left[i];
                left[i]=0;
            }else break;
        }
        return ans;
    }
};