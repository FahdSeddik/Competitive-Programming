class Solution {
public:
    string longestPrefix(string s) {
        int i=1,j=0,n=s.size();
        vector<int> lps(n);
        while(i<n){
            if(s[i]==s[j]){
                lps[i++]=j++ + 1;
            }else{
                if(j>0)j = lps[j-1];
                else lps[i++]=0;
            }
        }
        return s.substr(0,lps[n-1]);
    }
    
};