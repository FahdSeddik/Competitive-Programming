class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int,unordered_set<int>> mps;
        int x=0,y=0;
        mps[0].insert(0);
        for(char c : path){
            if(c=='N')y++;
            else if(c=='S')y--;
            else if(c=='E')x++;
            else x--;
            if(mps.count(x) && mps[x].count(y))return true;
            mps[x].insert(y);
        }
        return false;
    }
};