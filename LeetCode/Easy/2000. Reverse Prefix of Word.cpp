class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto begin = word.begin();
        while(begin != word.end() && *begin!=ch)begin++;
        if(begin==word.end())return word;
        reverse(word.begin(), ++begin);
        return word;
    }
};