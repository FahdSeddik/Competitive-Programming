class Solution {
public:
    int titleToNumber(string columnTitle) {
        if(columnTitle.size()==1)return columnTitle[0]-'A'+1;
        long long ans=0;
        for(long long n=columnTitle.size(),i=n-1,s=1;i>=0;i--,s*=26){
            ans += s*(columnTitle[i] -'A'+1);
        }
        return ans;
    }
};