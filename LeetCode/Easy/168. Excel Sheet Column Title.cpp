class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber){
            columnNumber--;
            ans+=(char)('A'+(columnNumber)%26);
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
/*
A-Z 1-26
AA-AZ 27-52
BA-BZ 53-78

*/