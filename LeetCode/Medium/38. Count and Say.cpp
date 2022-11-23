class Solution {
public:
    string getstring(string num){
        int cnt=1;
        char c = num[0];
        string ans;
        int i;
        for(i=1;i<num.size();i++){
            if(c!=num[i]){
                ans+=to_string(cnt);
                ans+=c;
                cnt=1;
                c=num[i];
            }else cnt++;
        }
        ans+=to_string(cnt);
        ans+=c;
        return ans;
    }
    string countAndSay(int n) {
        string num = to_string(n);
        string ans="1";
        for(int i=2;i<=n;i++){
            ans=getstring(ans);
        }
        return ans;
    }
};