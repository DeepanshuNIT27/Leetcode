class Solution {
public:
//Recursion
 int solveRec(string &word1,string &word2,int i , int j){
    //BASE CASE
    int ans = 0;
    if(i==word1.size() || j==word2.size()){
        ans += word1.size() - i ;
        ans += word2.size() - j ;
    }
    else if(word1[i]==word2[j])  ans = solveRec(word1,word2,i+1,j+1);
    else {
        int ans1 = 1 + solveRec(word1,word2,i+1,j);
        int ans2=  1 + solveRec(word1,word2,i,j+1);
        ans = min(ans1,ans2);
    }
    return ans;
 }
 //Memoization
 int solveMemo(string &word1,string &word2,int i , int j,vector<vector<int>>&dp){
    //BASE CASE
    int ans = 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==word1.size() || j==word2.size()){
        ans += word1.size() - i ;
        ans += word2.size() - j ;
    }
    else if(word1[i]==word2[j])  ans =solveMemo(word1,word2,i+1,j+1,dp);
    else {
        int ans1 = 1 + solveMemo(word1,word2,i+1,j,dp);
        int ans2=  1 + solveMemo(word1,word2,i,j+1,dp);
        ans = min(ans1,ans2);
    }
    dp[i][j] =  ans;
    return dp[i][j];
 }
 //Tabulation
 int solveTab(string&word1, string&word2){
    int ans = 0;
     int n = word1.size();
     int m = word2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=n-1;i>=0;i--) dp[i][m] = 1 + dp[i+1][m];
    for(int i=m-1;i>=0;i--) dp[n][i] = 1 + dp[n][i+1];

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
     if(word1[i]==word2[j])  ans = dp[i+1][j+1];
    else {
        int ans1 = 1 + dp[i+1][j];
        int ans2=  1 +  dp[i][j+1];
        ans = min(ans1,ans2);
    }
    dp[i][j] =  ans;
        }
    }
return  dp[0][0];
 }
 // Space optimization
 int solveSO(string&word1, string&word2){
    int ans = 0;
     int n = word1.size();
     int m = word2.size();
    vector<int>next(m+1,0) , curr(m+1,0);
    for(int i=m-1;i>=0;i--) next[i] = 1 + next[i+1];
    for(int i=n-1;i>=0;i--){
        curr[m] = 1 + next[m];
        for(int j=m-1;j>=0;j--){
     if(word1[i]==word2[j])  ans = next[j+1];
    else {
        int ans1 = 1 + next[j];
        int ans2=  1 + curr[j+1];
        ans = min(ans1,ans2);
    }
    curr[j] =  ans;
        }
        next = curr;
    }
return  next[0];
 }


    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        //Recursion
      // return  solveRec(word1,word2,0,0);

      //Memoization
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      //return solveMemo(word1,word2,0,0,dp);

      //Tabulation
     // return solveTab(word1,word2);

     //Space optimization
     return solveSO(word1,word2);
    }
};