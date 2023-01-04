class Solution {
public:
    string longestPalindrome(string s) {
        int st=0,en=0;
        for(int i=0;i<s.size();i++){
            int s1=i,s2=i+1,en1=i,en2=i;
            //even
            expandAroundCenter(s,s1,s2);
            //odd
            expandAroundCenter(s,en1,en2);
            if(abs(s2-s1)>abs(en2-en1)){
                if(abs(en-st)<abs(s2-s1))st=s1,en=s2;
            }else if(abs(en-st)<abs(en2-en1))st=en1,en=en2;
        }
        return s.substr(st+1,en-st-1);
    }

    void expandAroundCenter(string& s, int& st,int& en){
        while(st>=0 && en<s.size() && s[st]==s[en])st--,en++;
    }
};