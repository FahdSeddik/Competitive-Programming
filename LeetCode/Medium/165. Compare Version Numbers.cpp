class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream v1(version1), v2(version2);
        string vs1, vs2;
        while(true){
            bool v1Read = bool(getline(v1, vs1, '.'));
            bool v2Read = bool(getline(v2, vs2, '.'));
            if(!v1Read && !v2Read) break;
            vs1 = v1Read && !vs1.empty() ? vs1 : "0";
            vs2 = v2Read && !vs2.empty() ? vs2 : "0";
            int num1 = stoi(vs1), num2 = stoi(vs2);
            if(num1 < num2) return -1;
            else if(num1 > num2) return 1;
        }
        return 0;
    }
};