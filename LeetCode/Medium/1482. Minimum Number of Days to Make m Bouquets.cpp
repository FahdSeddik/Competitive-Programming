class Solution {
public:
    bool check(vector<int>& day, int cur, int m, int k, int cnt=0){
        for(int i=0;i<day.size() && m>0;i++){
            if(day[i]<=cur)cnt++;
            else m-=cnt/k,cnt=0;
        }
        m-=cnt/k;
        return m<=0;
    }
    int minDays(vector<int>& bloomDay, long long m, long long k) {
        ios::sync_with_stdio(0),cin.tie(0);
        if(m*k>bloomDay.size()) return -1;
        int ans,l=1,r=*max_element(bloomDay.begin(),bloomDay.end());
        while(l<=r){
            int mid=(r-l)/2+l;
            if(check(bloomDay,mid,m,k)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};
/*
we need smallest number where there are m groups of k consecutive 
elements smaller than or equal that number

1:  [x,_,_,_,_]
2:  [x,_,_,_,x]
3:  [x,_,x,_,x]
10: [x,x,x,x,x]
*/