class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int acc[101]={0};
        for(const auto& v:logs){
            acc[v[0]%1950]++,acc[v[1]%1950]--;
        }
        int ans=0;
        for(int i=1;i<101;i++){
            acc[i]=acc[i-1]+acc[i];
            if(acc[i]>acc[ans])ans=i;
        }
        return 1950+ans;
    }
};