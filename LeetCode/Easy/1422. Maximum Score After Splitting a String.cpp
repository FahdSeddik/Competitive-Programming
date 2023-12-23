class Solution {
public:
    int maxScore(string s) {
        int cntr = count(s.begin(),s.end(),'1'),cntl=0,mx=0;
        for(int i=0;i<s.size()-1;i++){
            cntl+=s[i]=='0';
            cntr-=s[i]=='1';
            mx=max(mx,cntl+cntr);
        }
        return mx;
    }
};