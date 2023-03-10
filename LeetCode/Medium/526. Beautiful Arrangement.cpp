class Solution {
    int N;
public:
    int dfs(int bm, int pl){
        if(!pl)return 1;
        int s=0;
        for(int i=0;i<N;i++){
            if(!(bm&1<<i) && ((i+1)%pl == 0 || pl%(i+1) == 0))s+=dfs(bm^1<<i, pl - 1);
        }
        return s;
    }
    int countArrangement(int n) {
        N=n;
        return dfs(0,n);
    }
};