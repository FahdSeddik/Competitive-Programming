class Solution {
public:
    bool tamam(vector<int>& time,long long& mid,int& tot){
        long long cur=0;
        for(const auto& t : time){
            cur+=mid/t;
        }
        return cur>=tot;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        long long l = 0,r=(long long)time[0]*(long long)totalTrips;
        while(l<r){
            long long mid = (l+r)/2;
            if(tamam(time,mid,totalTrips))r=mid;
            else l=mid+1;
        }
        return l;
    }
};