class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int count =0;
        int total =n*n,startingrow=0,startingcol=0,endingrow=n-1,endingcol=n-1;
        while(count<total)
        {
            for(int i=startingcol;count<total && i<=endingcol; i++)count++,ans[startingrow][i]=count;                
            startingrow++;            
            for(int i=startingrow;count<total && i<=endingrow; i++)count++,ans[i][endingcol]=count;
            endingcol--;            
            for(int i=endingcol;count<total && i>=startingcol; i--)count++,ans[endingrow][i]=count;
            endingrow--;            
            for(int i=endingrow;count<total && i>=startingrow; i--)count++,ans[i][startingcol]=count;
            startingcol++;
        }
        return ans;
    }
};