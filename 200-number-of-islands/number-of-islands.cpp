class Solution {

    void dfs(vector<vector<char>>& grid,
             vector<vector<int>>& vis,
             int row,
             int col){

        int m = grid.size();
        int n = grid[0].size();

        // out of bounds
        if(row < 0 || col < 0 ||
           row >= m || col >= n)
            return;

        // water or visited
        if(grid[row][col] == '0' ||
           vis[row][col])
            return;

        vis[row][col] = 1;

        // 4 directions
        dfs(grid,vis,row+1,col);
        dfs(grid,vis,row-1,col);
        dfs(grid,vis,row,col+1);
        dfs(grid,vis,row,col-1);
             }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count =0;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1' &&
                   !vis[i][j]){
                    dfs(grid,vis,i,j);
                    count++;
                }
            }
            

        }
        return count;
        
    }
};