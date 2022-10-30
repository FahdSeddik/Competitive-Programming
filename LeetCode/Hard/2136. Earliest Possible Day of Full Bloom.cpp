class Solution {
public:
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> arr;
	    int n = plantTime.size();
	    for (int i = 0; i < n; ++i){
		    pair<int, int> p = {growTime[i], plantTime[i]};
		    arr.push_back(p);
	    }
	    sort(arr.begin(), arr.end(), greater<pair<int, int>>());
	    int totalDays = arr[0].first + arr[0].second;
	    int plantAndGrowthDays = arr[0].second;
	    for (int i = 1; i < n; ++i){
    		plantAndGrowthDays += arr[i].second;
    		totalDays = max(totalDays,plantAndGrowthDays + arr[i].first);
    	}
    	return totalDays;
    }
};