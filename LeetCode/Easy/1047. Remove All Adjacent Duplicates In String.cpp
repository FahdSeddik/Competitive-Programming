class Solution {
public:
    string removeDuplicates(string s) {
        string answer;
        for (auto& x : s) 
            if (answer.size() && answer.back() == x) answer.pop_back();
            else answer.push_back(x);
        return answer;
    }
};