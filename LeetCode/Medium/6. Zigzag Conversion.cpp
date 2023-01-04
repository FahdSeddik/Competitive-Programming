class Solution {
public:
    string convert(string s, int numRows) {
        string ans="";
        // 1 2 3 4 3 2 1 2 3 4
        // 0 1 2 3 4 5 6
        if(numRows==1)return s;
        int z=2*(numRows-1),t=z;
        for(int j=0;j<s.size();j+=z)ans+=s[j];
        for(int i=1;i<numRows-1;i++){
            z=t-2*i;
            z=t-z;
            for(int j=i;j<s.size();z=t-z,j+=z)ans+=s[j];
        }
        for(int j=numRows-1;j<s.size();j+=t)ans+=s[j];
        return ans;
    }
};