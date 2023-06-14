class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cd) {
        for(int i=2;i<cd.size();i++){
            if((cd[i][1]-cd[0][1])*(cd[1][0]-cd[0][0])!=(cd[1][1]-cd[0][1])*(cd[i][0]-cd[0][0]))return false;
        }
        return true;
    }
};