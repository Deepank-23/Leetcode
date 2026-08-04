class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        if (totalGas < totalCost) return -1;
        vector<int> tank(gas.size(),0);
        int dif =0;
        for (int i = 0 ;i<gas.size();i++){

            dif= gas[i]-cost[i];
            if ( i ==0) tank[i] = dif;
            else tank[i] = tank[i-1] + dif;
        }
        auto it =  min_element(tank.begin(),tank.end());
        int ind = it - tank.begin();
        int i =(ind + 1) % gas.size();
        return (ind + 1) % gas.size();
        
    }
};