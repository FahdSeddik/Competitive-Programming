class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        for(auto v : pushed){
            pushed[i++]=v;
            while(i>0 && pushed[i-1]==popped[j])--i,++j;
        }
        return !i;
    }
};