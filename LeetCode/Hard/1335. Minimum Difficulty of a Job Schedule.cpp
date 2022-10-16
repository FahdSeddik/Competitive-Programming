class Solution {
    int dp[301][11];
    int calc(vector<int>& jd, int& n,int day , int i=0){
        if(day==1) return *max_element(jd.begin()+i,jd.end());
        if(dp[i][day]!=-1)return dp[i][day];
        int mx = INT_MIN;
        int res = INT_MAX;
        for(int j = i;j<=n-day;j++){
            mx = max(mx,jd[j]);
            res = min(res,mx + calc(jd,n,day-1,j+1));
        }
        return dp[i][day] = res;
        
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d)return -1;
        memset(dp,-1,sizeof(dp));
        return calc(jobDifficulty,n,d);
    }
};