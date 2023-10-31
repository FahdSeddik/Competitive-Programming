class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int a,int b){
            int ac=__builtin_popcount(a),bc=__builtin_popcount(b);
            return ac==bc ? a<b:ac<bc;
        });
        return arr;
    }
};