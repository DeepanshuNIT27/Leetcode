class Solution {
public:

//RECURSION 
int solveRec(int i, int j, string &s, string &t){

    //BASE CASE
    if(j == t.size()) return 1;

    if(i == s.size()) return 0;
    int ans = 0;
    if(s[i] == t[j]){

        int ans1 = solveRec(i+1,j+1,s,t);
        int ans2 = solveRec(i+1,j,s,t);

        ans  =  ans1 + ans2;
    }
    else {
        ans = solveRec(i+1,j,s,t);
    }

    return ans;
}

//MEMOIZATION 
int solveMemo(int i, int j, string &s, string &t, vector<vector<long long>>&dp){

    //BASE CASE
    if(j == t.size()) return  dp[i][j] = 1;

    if(i == s.size()) return dp[i][j] =  0;
    if(dp[i][j]!=-1) return  dp[i][j];
    int ans = 0;
    if(s[i] == t[j]){

        int ans1 = solveMemo(i+1,j+1,s,t,dp);
        int ans2 = solveMemo(i+1,j,s,t,dp);

        ans  =  ans1 + ans2;
    }
    else {
        ans = solveMemo(i+1,j,s,t,dp);
    }

    return  dp[i][j] = ans;
}

//TABULATION 
int solveTab(string &s, string &t){

      int n = s.size();
      int m = t.size();
      vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(m+1,0));

    //BASE CASE
    for(int i=0;i<=n;i++){
        dp[i][m] = 1;
    }
   for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){

        if(n-i < m-j) continue;

    
    if(s[i] == t[j]){
       unsigned  long long  ans1 = dp[i+1][j+1];
       unsigned  long long  ans2 = dp[i+1][j];
        dp[i][j]  =  ans1 + ans2;
    }
    else {
        dp[i][j] = dp[i+1][j];
    }
    }
   }
   return dp[0][0];
}


    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        //RECURSION 
       // return solveRec(0,0,s,t);

       //MEMOIZATION 
      // vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));
       //return solveMemo(0,0,s,t,dp);

       //TABULATION 
       return solveTab(s,t);
    }
};