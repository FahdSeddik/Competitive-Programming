class Solution {
public:
    bool isVowel(char c){
        c = c>='a' ? c:c-'A'+'a';
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    string sortVowels(string s) {
        int freq[128]={0},idx=0;
        for(char c : s){
            if(isVowel(c))freq[(int)c]++;
        }
        for(char& c : s){
            if(isVowel(c)){
                while(freq[idx]==0)idx++;
                c=(char)idx,freq[idx]--;
            }
        }
        return s;
    }
};