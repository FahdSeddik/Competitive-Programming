class Solution {
    vector<string> ans;
public:
    void fill(int left,int right,string s=""){
        if(left<0 || right<0)return;
        if(left<=0 && right<=0){
            ans.push_back(s);
            return;
        }
        if(left>=right){
            fill(left-1,right,s+'(');
        }else{
            fill(left-1,right,s+'(');
            fill(left,right-1,s+')');
        }
        
    }
    vector<string> generateParenthesis(int n) {
        ans = vector<string>();
        fill(n,n);
        return ans;
    }
};

