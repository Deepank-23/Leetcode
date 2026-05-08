class Solution {
public:
bool issafe(vector<vector<char>> &board,int row,int col,int num){
   
    int n = board.size();
    if(num=='.')return true;
    for(int i = 0;i<n;i++){
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
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
   
    for(int i =0;i<board.size();i++){
        for(int j =0;j<board.size();j++){
            int num = board[i][j];
            board[i][j] = '.';
            if(!issafe(board,i,j,num)){
                return false;
            }
            board[i][j] =num;
            
        
    }
    }
    return true;
    }
};