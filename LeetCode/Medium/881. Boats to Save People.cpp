class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l=0,r=people.size()-1,ans=0;
        while(l<=r){
            ans++;
            if(people[l]+people[r]<=limit)l++;
            r--;
        }
        return ans;
    }
};