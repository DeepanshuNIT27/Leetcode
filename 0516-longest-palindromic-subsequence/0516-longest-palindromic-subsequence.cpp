class Solution {
public:
//RECURSION 
int solveRec(int i , int j , string &s){

    if(i==j) return 1;
    if(i>j) return 0;
    
    int ans1 = 0; int ans2 = 0;
    if(s[i]==s[j]) ans1  = 2 + solveRec(i+1,j-1,s);
    else ans2 = max(solveRec(i+1,j,s) , solveRec(i,j-1,s));

    return max(ans1,ans2);

}

//MEMOIZATION 
int solveMemo(int i , int j , string &s,vector<vector<int>>&dp){

    if(i==j) return 1;
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans1 = 0; int ans2 = 0;
    if(s[i]==s[j]) ans1  = 2 + solveMemo(i+1,j-1,s,dp);
    else ans2 = max(solveMemo(i+1,j,s,dp) , solveMemo(i,j-1,s,dp));

    return  dp[i][j] = max(ans1,ans2);

}
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int i = 0;
        int j = s.size()-1;
        //RECURSION 
        //return solveRec(i,j,s);

        //MEMOIZATION 
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveMemo(i,j,s,dp);
    }
};