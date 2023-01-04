class Solution {
    vector<string> ans,numpad;
public:
    void getNumpad(string& digits,int i,string s=""){
        if(i==digits.size()){
            ans.push_back(s);
            return;
        }
        for(auto c : numpad[digits[i]-'0'-2]){
            getNumpad(digits,i+1,s+c);
        }
    }
    vector<string> letterCombinations(string digits) {
        numpad= vector<string>{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.empty())return {};
        getNumpad(digits,0);
        return ans;
    }
};