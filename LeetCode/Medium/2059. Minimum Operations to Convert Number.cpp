class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        if(start==goal)return 0;
        int depth[1001];memset(depth,-1,sizeof(depth));
        queue<int> q;
        int size=1;
        q.push(start),depth[start]=0;
        for(;!q.empty();size=q.size()){
            while(size--){
                int x = q.front();q.pop();
                if(x==goal)return depth[x];
                for(int u : nums){
                    int a=x+u,b=x-u,c=x^u;
                    if(a==goal || b==goal || c==goal)return depth[x]+1;
                    if(a>=0 && a<=1000 && depth[a]==-1)q.push(a),depth[a]=depth[x]+1;
                    if(b>=0 && b<=1000 && depth[b]==-1)q.push(b),depth[b]=depth[x]+1;
                    if(c>=0 && c<=1000 && depth[c]==-1)q.push(c),depth[c]=depth[x]+1;
                }
            }
        }
        return -1;
    }
};