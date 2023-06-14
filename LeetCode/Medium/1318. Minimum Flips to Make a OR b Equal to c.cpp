class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0,t=1;
        for(int i=0;i<31;i++){
            int ta=a&t,tb=b&t,tc=c&t;
            if(tc){
                if(!ta && !tb)ans++;
            }
            if(!tc){
                if(ta)ans++;
                if(tb)ans++;
            }
            t<<=1;
        }
        return ans;
    }
};