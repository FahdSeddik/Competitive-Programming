class Solution {
    int parent[26];
public:
    int find(int x){
        return x==parent[x] ? x : parent[x]=find(parent[x]);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i=0;i<26;i++)parent[i]=i;
        for(int i=0;i<s2.size();i++){
            int c1 = find(s1[i]-'a');
            int c2 = find(s2[i]-'a');
            if(c1<c2)parent[c2]=c1;
            else parent[c1]=c2;
        }
        for(int i=0;i<baseStr.size();i++){
            baseStr[i]=(char)(find(baseStr[i]-'a')+'a');
        }
        return baseStr;
    }
};