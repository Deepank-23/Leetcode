class Solution {
public:
    int minm(int n,vector<int>&cost,vector<int>&dp){
        if(n==1||n==0) return cost[n];
        if(dp[n]!=-1)return dp[n];
        
        return dp[n]=cost[n] +min(minm(n-1,cost,dp),minm(n-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(cost.size(),-1);
        return min(minm(n-1,cost,dp),minm(n-2,cost,dp));
        
    }
};