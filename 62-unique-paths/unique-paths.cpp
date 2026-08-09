class Solution {
public:

    int ways(int m , int n,vector<vector<int>>& dp){
        if(m==1 ||n==1)return dp[m-1][n-1]=1;
        if(dp[m-1][n-1]!=0)return dp[m-1][n-1];
        return dp[m-1][n-1]=ways(m-1,n,dp)+ways(m,n-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,(vector<int>(n,0)));
        return ways(m,n,dp);
    }
};