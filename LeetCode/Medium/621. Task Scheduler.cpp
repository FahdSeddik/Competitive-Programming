class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        int maxf=0,maxfc=0;
        for(char task : tasks){
            freq[task-'A']++;
            if(freq[task-'A'] > maxf){
                maxf = freq[task-'A'];
                maxfc = 1;
            } else if(freq[task-'A'] == maxf)maxfc++;
        }
        return max((int)tasks.size(), (maxf - 1) * (n + 1) + maxfc);
    }
};