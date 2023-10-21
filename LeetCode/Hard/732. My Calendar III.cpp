class MyCalendarThree {
    map<int,int> mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++,mp[endTime]--;
        int cur=0,ans=0;
        for(auto& x : mp){
            cur+=x.second;
            ans=max(ans,cur);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */