class Solution {
public:
    bool isSimilar(string a,string b){
        int cnt=0;
        for(int i=0;i<a.size() && cnt<=2;i++){
            if(a[i]!=b[i])cnt++;
        }
        return cnt==2 || cnt==0;
    }
    int parent[301];
    int find(int x){
        return x==parent[x] ? x:parent[x]=find(parent[x]);
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        iota(parent,parent+301,0);
        int ans=n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    int x = find(i),y=find(j);
                    parent[x]=parent[y];
                    ans-=x!=y;                   
                }
            }
        }
        return ans;
    }
};