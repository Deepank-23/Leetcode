class Solution {
public:
    int cost(vector<vector<int>>& grid,vector<vector<int>>&dp,int i ,int j){
        if(i==0 && j==0)return dp[i][j] = grid[i][j];
        else if(i<0||j<0)return 1e9;
        else if (dp[i][j]!=-1)return dp[i][j];

        return dp[i][j]=min(cost(grid,dp,i-1,j)+grid[i][j],cost(grid,dp,i,j-1)+grid[i][j]);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        
        return cost(grid,dp,grid.size()-1,grid[0].size()-1);
    }
};