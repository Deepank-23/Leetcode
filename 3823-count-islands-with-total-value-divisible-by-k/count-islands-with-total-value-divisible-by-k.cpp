class Solution {
public:
    long long check(vector<vector<int>>&grid , int i , int j){
        int rows = grid.size();
        int col = grid[0].size();
        if(i<0||j<0 || i> rows-1|| j>col-1 || grid[i][j]==0)return 0 ;
        long long sum =grid[i][j];
        grid[i][j]=0;
        sum += check(grid, i - 1, j);
        sum += check(grid, i + 1, j);
        sum += check(grid, i, j - 1);
        sum += check(grid, i, j + 1);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int col = grid[0].size();
        int count = 0;

        for(int i = 0 ; i<rows;i++){
            for(int j =0 ; j<col;j++){
                if(grid[i][j]!=0){
                    
                    if(check(grid,i,j)%k==0)count++;
                }  
            }
           
            

        }
        return count;


    }
};