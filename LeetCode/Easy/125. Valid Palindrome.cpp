class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(char c : s)if(isalpha(c) || (c-'0'>=0 &&c-'0'<=9))str+=tolower(c);
        string s1,s2;
        if(str.size()%2==0){
            s1 = str.substr(0,str.size()/2);
            s2 = str.substr(str.size()/2,str.size()/2);
        }else{
            s1 = str.substr(0,str.size()/2);
            s2 = str.substr(str.size()/2+1,str.size()/2);
        }
        reverse(s2.begin(),s2.end());
        return s1==s2;
    }
};