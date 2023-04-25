class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(const auto& s : wordList)dict.insert(s);
        queue<string> q;
        q.push(beginWord);
        int size=1,depth=1;
        for(;!q.empty();size=q.size(),depth++){
            while(size--){
                string u = q.front();q.pop();
                if(u==endWord)return depth;
                for(int i=0;i<u.size();i++){
                    for(char c='a';c<='z';c++){
                        string temp=u;
                        temp[i]=c;
                        if(dict.count(temp)){
                            q.push(temp);
                            dict.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};