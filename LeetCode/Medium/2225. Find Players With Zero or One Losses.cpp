class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int plays[100'001]={0},loss[100'001]={0};
        for(auto m : matches){
            plays[m[0]]++,plays[m[1]]++,loss[m[1]]++;
        }
        vector<int> ans1,ans2;
        for(int i=0;i<100001;i++){
            if(plays[i] && !loss[i])ans1.push_back(i);
            if(plays[i] && loss[i]==1)ans2.push_back(i);
        }
        return {ans1,ans2};
    }
};