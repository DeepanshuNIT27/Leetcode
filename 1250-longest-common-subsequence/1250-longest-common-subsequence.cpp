class Solution {
public:
  int solveUsingRec(string text1, string text2 , int i ,int j){
    //BASE CASE
    if(i>= text1.size() || j>= text2.size()) return 0;
     int ans = 0;
    //MATCH
    if(text1[i] == text2[j]){
        ans = 1 + solveUsingRec(text1,text2,i+1,j+1);
    }
    //NOT
    else{
        ans = 0 + max(solveUsingRec(text1,text2,i+1,j) ,solveUsingRec(text1,text2,i,j+1));
    }
    return ans;
  }
  //2d dp Memo
  int solveUsingMemo(string &text1, string &text2 , int i ,int j,vector<vector<int>>&dp){
    //BASE CASE
    if(i>= text1.size() || j>= text2.size()) return 0;

    if(dp[i][j]!= -1) return dp[i][j];
     int ans = 0;
    //MATCH
    if(text1[i] == text2[j]){
        ans = 1 + solveUsingMemo(text1,text2,i+1,j+1,dp);
       
    }
    //NOT
    else{
        ans = 0 + max(solveUsingMemo(text1,text2,i+1,j,dp) ,solveUsingMemo(text1,text2,i,j+1,dp));
       
    }
    dp[i][j] = ans;
    return dp[i][j];
  }

    int longestCommonSubsequence(string text1, string text2) {
        //recursion
        int i =0;
        int j= 0;
        // return solveUsingRec(text1,text2,i,j);

        // Memo
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      return  solveUsingMemo(text1,text2,i,j,dp);
    }
};