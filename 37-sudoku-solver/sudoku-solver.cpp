class Solution {
int check = 0;
public:
bool issafe(vector<vector<char>> &board,int row,int col,char num){
   
    int n = board.size();
    if(num==0)return true;
    for(int i = 0 ;i<n;i++){
        if(board[i][col]==num)return false;

    }
    for(int j = 0 ;j<n;j++){
        if(board[row][j]==num)return false;

    }
    int x=row/3;
    int y = col/3;
    for(int i = 3*x;i<3*(x+1);i++){
        for(int j =3*y;j<3*(y+1);j++){
            if(board[i][j]==num)return false;
        }
    }
    return true;


}
void solve(vector<vector<char>>& board,int row,int col){
    if(row==9){
        check =1;
        return ;
    }
    else if(board[row][col]!='.'){
        if(col!=8){
            solve(board,row,col+1);
            }
            else solve(board,row+1,0);
    }
    else{
        for(char ch='1';ch<='9';ch++){
            if(issafe(board,row,col,ch)){
                board[row][col]=ch;
                if(col!=8){
                    solve(board,row,col+1);
                }
                else solve(board,row+1,0);
                if(check ==1)return;
                board[row][col]='.';
            }
        }
    }

}
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board,0,0);
        check =0;
        
    }
};