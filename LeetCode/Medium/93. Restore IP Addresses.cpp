class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        const int N = s.size();
        if(N<4 || N >12){
            return {};
        }
        vector<string> ans;
        vector<int> comb;
        function<void(int, int)> backtracking = [&](int level, int begin){
            if(level == 4){
                if(begin == N){
                    string ip = "";
                    int idx = 1;
                    for(int i = 0; i < N; ++i){
                        if(idx < 4 && comb[idx] == i){
                            ip += '.';
                            ++idx;
                        }
                        ip += s[i];
                    }
                    ans.push_back(ip);
                }
                return;
            }
            comb.push_back(begin);
            if(s[begin] == '0'){
                backtracking(level + 1, begin + 1);
            }else{
                for(int end = begin; end < begin + 3 && end < N; ++end){
                    if(!isValid(s, begin, end)){
                        continue;
                    }
                    backtracking(level + 1, end + 1);
                }
            }
            comb.pop_back();
        };
        backtracking(0, 0);
        return ans;
    }
    bool isValid(const string& s, int begin, int end){
        int num = 0;
        for(int i = begin; i <= end; ++i){
            num = num * 10 + (s[i] - '0');
        }
        return num > 0 && num <= 255;
    }
};