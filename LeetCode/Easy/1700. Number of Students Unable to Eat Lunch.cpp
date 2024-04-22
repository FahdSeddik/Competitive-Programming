class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int z=0,o=0;
        for(int v : students)if(v==0)z++;else o++;
        for(int i=0;i<sandwiches.size();i++){
            if(sandwiches[i]==1 && o>0){
                o--;
                continue;
            }else if(sandwiches[i]==0 && z>0){
                z--;
                continue;
            }else return sandwiches.size()-i;
        }
        return 0;
    }
};