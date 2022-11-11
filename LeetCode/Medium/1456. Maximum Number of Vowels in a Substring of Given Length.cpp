class Solution {
public:
    bool vowel(char& c){
        return c=='a' || c=='e' || c=='i' || c=='u' || c=='o';
    }
    int maxVowels(string s, int k) {
        int num=0,mx=0,i=0;
        for(i=0;i<k;i++)num+= (vowel(s[i]) ?  1 : 0);
        mx = max(mx,num);
        for(;i<s.size();i++){
            num+= (vowel(s[i]) ?  1 : 0) - (vowel(s[i-k]) ?  1 : 0);
            mx = max(mx,num);
        }
        return mx;
    }
};