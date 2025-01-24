class Solution {
public:
      bool issafe(char digit,int i,int j,vector<vector<char>>& board){
        //ROW
        for(int k=0 ;k<9 ;k++){
            if(board[i][k]==digit){
                return false;
            }
        }
        //COLUMN
        for(int k=0;k<9 ;k++){
            if(board[k][j]== digit){
                return false;
            }
        }
        //3*3
        for(int k=0 ;k<9 ;k++){
         if(board[3*(i/3)+k/3][3*(j/3)+k%3] == digit){
            return false;
         }                            
      }
      return true;
      }
       bool solve(vector<vector<char>>& board){
        for(int i=0 ;i<board.size();i++){
            for(int j=0 ;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char digit='1' ;digit<='9' ;digit++){
                        if(issafe(digit,i,j,board)==true){
                            board[i][j] = digit;
                            bool aagesolvehopaya = solve(board);
                            if(aagesolvehopaya){
                                return true;
                            }
                            else{
                                board[i][j] ='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
       }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};