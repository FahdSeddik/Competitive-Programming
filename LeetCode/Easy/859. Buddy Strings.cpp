class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n=s.size();
        if(n!=goal.size())return false;
        int freq[26]={0};
        if(s==goal){
            for(auto c : s)freq[c-'a']++;
            for(auto i : freq)if(i>=2)return true;
            return false;
        }
        int b=0;
        for(int i=0;i<n && b<=2;i++)b+=s[i]!=goal[i],freq[s[i]-'a']++,freq[goal[i]-'a']--;
        for(auto i : freq)if(i!=0)return false;
        return b==2;
    }
};