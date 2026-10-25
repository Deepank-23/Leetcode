class Solution {
public:
    void dfs(vector<vector<int>> &grid,int i ,int j ){
        int rows = grid.size();
        int cols = grid[0].size();
        if(i<0||j<0||i>=rows||j>=cols||grid[i][j]!=0)return;
        grid[i][j]=1;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);

    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for(int i =0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if(i==00||j==0||i==rows-1||j==cols-1){
                    if(grid[i][j]==0) dfs(grid,i,j);


                }
            }
        }
        for(int i =0;i<rows;i++){
            for(int j =0;j<cols;j++){ 
                if(grid[i][j]==0) {
                    count++;
                    dfs(grid,i,j);
                }
                
            }
        }
        return count;
    }
};