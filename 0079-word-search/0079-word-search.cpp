class Solution {
public:
bool solve(vector<vector<char>>& board,string &word,int row , int col , int i){
    //base case
    if(i>=word.size()) return true;
    if(row<0 || row>=board.size() || col<0 || col>=board[0].size()|| board[row][col]!=word[i] || board[row][col]=='%') return false;

    // ek case hm dekhenge
    int dx[]=  {1,-1,0,0};
    int dy[] = { 0,0,1,-1};
      char temp = board[row][col];
      board[row][col] = '%';
    bool ans = false;
    for(int j=0;j<4;j++){
     bool ans2 = solve(board,word,row+dx[j],col+dy[j],i+1);
     ans =  ans || ans2;
    }
    //backtrack
    board[row][col] = temp;
    return ans;
}
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};