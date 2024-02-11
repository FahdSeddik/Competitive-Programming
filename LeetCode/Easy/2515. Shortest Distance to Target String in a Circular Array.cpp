class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        queue<int> q;
        q.push(startIndex);
        int n = words.size(),size=1,depth=0;
        vector<int> vis(n);
        for(;!q.empty();size=q.size(),depth++){
            while(size--){
                int idx = q.front();q.pop();
                if(words[idx]==target)return depth;
                vis[idx]=true;
                if(!vis[(idx+1)%n])q.push((idx+1)%n);
                if(!vis[(idx-1+n)%n])q.push((idx-1+n)%n);
            }
        }
        return -1;
    }
};