class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    string categorizeBox(int length, int width, int height, int mass) {
        bool Bulky = length>=1e4 || width>=1e4 || height>=1e4 ||((long long)length*width*height>=1e9);
        bool Heavy = mass>=100;
        if(Bulky && Heavy)return "Both";
        else if(Bulky)return "Bulky";
        else if(Heavy)return "Heavy";
        else return "Neither";
    }
};