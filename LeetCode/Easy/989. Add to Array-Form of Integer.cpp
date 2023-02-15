class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int i=num.size()-1,cur=0,rem=0,idx=0;
        //construct only from k;
        while(k){
            ans.push_back(k%10);
            k/=10;
        }
        while(i>=0){
            if(idx>=ans.size())cur=rem+num[i--],ans.push_back(cur%10),rem=cur/10,idx++;
            else{
                cur = rem+num[i--]+ans[idx];
                rem = cur/10;
                ans[idx++]=cur%10;
            }
        }
        if(rem){
            if(idx>=ans.size())ans.push_back(rem);
            else {
                while(rem){
                    if(idx>=ans.size())cur=rem,ans.push_back(cur%10),rem=cur/10;
                    else{
                    cur = ans[idx]+rem;
                    rem = cur/10;
                    ans[idx++]=cur%10;
                    }
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};