class Solution {
public:
    bool checkValid(vector<int>& position, int diff, int m){
        int idx=0,start,n=position.size();
        // cout<<"\n==== "<<diff<<" ====\n";
        // cout<<idx<<" ";
        while(m>1 && idx<n){
            idx=lower_bound(position.begin()+idx,position.end(),position[idx]+diff)-position.begin();
            if(idx<n)m--;
            // cout<<"("<<idx<<", "<<m<<") ";
        }
        return m==1;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l=1,r=position.back()-position[0],ans=1;
        while(l<=r){
            int mid=(r-l)/2+l;
            if(checkValid(position,mid,m))l=mid+1,ans=mid;
            else r=mid-1;
        }
        return ans;
    }
};