class Solution {
public:
//RECURSION 
int solveRec(int i, int j , vector<int>& piles ){
    if(i>j) return 0;

    if(i==j) return piles[i];

    int front =  piles[i] - solveRec(i+1,j,piles);
    int back  = piles[j] - solveRec(i,j-1,piles);

    return max(front,back);
}

//MEMOIZATION 
int solveMemo(int i, int j , vector<int>& piles, vector<vector<int>>&dp ){
    if(i>j) return 0;

    if(i==j) return piles[i];

    if(dp[i][j]!=INT_MIN) return dp[i][j];

    int front =  piles[i] - solveMemo(i+1,j,piles,dp);
    int back  = piles[j] - solveMemo(i,j-1,piles,dp);

    return  dp[i][j] = max(front,back);
}

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int i = 0;
        int j = n-1;
        //RECURSION
        // int ans = solveRec(i,j,piles);
        // if(ans>0) return true;
        // return false;

        //MEMOIZATION 
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MIN));
         int ans = solveMemo(i,j,piles,dp);
        if(ans>0) return true;
        return false;
    }
};