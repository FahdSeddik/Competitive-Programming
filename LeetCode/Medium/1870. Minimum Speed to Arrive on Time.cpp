class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour<=n-1)return -1;
        int l=1,r=1e7;
        while(l<r){
            int mid = l+(r-l)/2;
            double tot = 0;
            for(int i=0;i<n-1;i++){
                tot+= (dist[i]+mid-1)/mid;
            }
            tot+=(double)dist[n-1]/mid;
            if(tot<=hour)r=mid;
            else l=mid+1;
        }
        return l;
    }
};