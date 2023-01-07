class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int ans=0,tot_g=0,tot_c=0,tank=0;
        for(int i=0;i<n;i++){
            tank+= gas[i]-cost[i];
            if(tank<0)ans=i+1,tank=0;
            tot_g+=gas[i],tot_c+=cost[i];
        }
        return tot_g<tot_c ? -1:ans;
    }
};