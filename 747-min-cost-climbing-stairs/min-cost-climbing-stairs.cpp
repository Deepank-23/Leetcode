class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(cost.size(),-1);

        int i =0;
        while(i<n){
            if(i<2) dp[i] =cost[i];
            else dp[i]=cost[i] +min(dp[i-1],dp[i-2]);
            i++;
        }
        return min(dp[n-1],dp[n-2]);
        
    }
};