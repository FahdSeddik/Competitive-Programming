class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones=0,flipped=0;
        for(const auto& c : s){
            if(c=='1')ones++;
            else {
                flipped++;
                flipped = min(ones,flipped);
            }
        }
        return flipped;
    }
};