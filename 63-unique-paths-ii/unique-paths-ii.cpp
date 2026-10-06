class Solution {
public:
    int ways(vector<vector<int>> &obstacleGrid,int m ,int n,vector<vector<int>> & dp){
        if (m < 0 || n < 0) return 0;
        if(obstacleGrid[m][n]==1) return 0;
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=0)return dp[m][n];

        return dp[m][n]=ways(obstacleGrid,m-1,n,dp)+ways(obstacleGrid,m,n-1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        return ways(obstacleGrid,m-1,n-1,dp);
        
        
    }
};