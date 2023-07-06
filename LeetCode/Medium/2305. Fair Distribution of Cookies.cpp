class Solution {
    vector<int> children;
    int ans;
public:
    void distr(vector<int>& cookies,int i=0){
        if(i==cookies.size()){
            ans=min(ans,*max_element(children.begin(),children.end()));
            return;
        }
        for(auto& j : children){
            j+=cookies[i];
            distr(cookies,i+1);
            j-=cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        children.resize(k);
        ans=INT_MAX;
        distr(cookies);
        return ans;
    }
};