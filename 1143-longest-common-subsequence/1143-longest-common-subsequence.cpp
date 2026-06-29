class Solution {
public:
//RECURSION 

int solveRec(int i, int j ,string &text1, string &text2 ){

    if(i == text1.size() || j == text2.size()) return 0;
    
    int ans = 0;
    if(text1[i] == text2[j]){
      ans = 1 + solveRec(i+1,j+1,text1,text2);
    }
    else {

        int ans2 = solveRec(i+1,j,text1,text2);
        int ans3 = solveRec(i,j+1,text1,text2);

        ans = max(ans,max(ans2,ans3));
    }
    return  ans;
}

//MEMOIZATION

int solveMemo(int i, int j ,string &text1, string &text2, vector<vector<int>>&dp ){

    if(i == text1.size() || j == text2.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans = 0;
    if(text1[i] == text2[j]){
      ans = 1 + solveMemo(i+1,j+1,text1,text2,dp);
    }
    else {

        int ans2 = solveMemo(i+1,j,text1,text2,dp);
        int ans3 = solveMemo(i,j+1,text1,text2,dp);

        ans = max(ans,max(ans2,ans3));
    }
    return  dp[i][j] = ans;
}

//TABULATION

int solveTab(string &text1, string &text2){
      int n = text1.size();
      int m = text2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int ans = 0;
        if(text1[i] == text2[j]){
      ans = 1 + dp[i+1][j+1];
       }
    else {
        int ans2 = dp[i+1][j];
        int ans3 = dp[i][j+1];
        ans = max(ans,max(ans2,ans3));
    }
       dp[i][j] = ans;
        }
    }

return dp[0][0];
}

//SPACE OPTIMIZATION 
int solveSO(string &text1, string &text2){
      int n = text1.size();
      int m = text2.size();
    vector<int>curr(m+1,0);
    vector<int>next(m+1,0);

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int ans = 0;
        if(text1[i] == text2[j]){
      ans = 1 + next[j+1];
       }
    else {
        int ans2 = next[j];
        int ans3 = curr[j+1];
        ans = max(ans,max(ans2,ans3));
    }
      curr[j] = ans;
        }
        next = curr;
    }

return next[0];
}




    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
          //RECURSION 
        //return solveRec(0,0,text1,text2);

        //MEMOIZATION 
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       // return solveMemo(0,0,text1,text2,dp);

       //TABULATION 
       //return solveTab(text1,text2);

       //SPACE OPTIMIZATION 
       return solveSO(text1,text2);
    }
};