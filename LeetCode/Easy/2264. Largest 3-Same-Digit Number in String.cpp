class Solution {
public:
    string largestGoodInteger(string num) {
        char last='/',ans='/';
        int cnt=0;
        for(auto c : num){
            if(c==last)cnt++;
            else last=c,cnt=1;
            if(cnt==3 && ans<c)ans=c;
        }
        return ans=='/' ? "":string(3,ans);
    }
};