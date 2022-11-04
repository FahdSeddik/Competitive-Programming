class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0,j=s.size()-1;i<j;){
            while(!st.count(s[i]) && i<j)i++;
            while(!st.count(s[j]) && i<j)j--;
            swap(s[i],s[j]);
            i++,j--;
        }
        return s;
    }
};