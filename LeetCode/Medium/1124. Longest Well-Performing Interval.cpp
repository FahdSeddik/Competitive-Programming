class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        unordered_map<int,int> mp;
        hours[0]=hours[0]>8 ? 1:-1;
        mp[hours[0]]=0;
        for(int i=1;i<n;i++)hours[i]=hours[i-1]+(hours[i]>8 ? 1:-1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(hours[i]>0)ans=i+1;
            else {
                if(mp.count(hours[i]-1))ans=max(ans, i-mp[hours[i]-1]);
                if(!mp.count(hours[i]))mp[hours[i]]=i;
            }
            
        }
        return ans;
    }
};

/*
[1, 1,-1,-1,-1,-1, 1]
[1, 2, 1, 0,-1,-2,-1]
[1, 2, 3]
*/