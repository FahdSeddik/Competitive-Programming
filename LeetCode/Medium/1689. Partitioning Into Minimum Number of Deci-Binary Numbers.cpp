class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(auto c: n){
            if(c-'0'>ans)ans=c-'0';
        }
        return ans;
    }
};