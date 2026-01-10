class Solution {
public:
//Recursion
int solveRec(string &s1, string &s2 , int i , int j){
    //BASE CASE
    int ans = 0;
    if(i==s1.size() || j==s2.size()) {
        for(int k=i;k<s1.size();k++)  ans += s1[k];
        for(int k=j;k<s2.size();k++) ans += s2[k];
     }
     //dono same hai 
   else if(s1[i]==s2[j])  ans  = solveRec(s1,s2,i+1,j+1);
    else {
    // s1 delte hoga 
      int  ans1 = s1[i] + solveRec(s1,s2,i+1,j);
    //s2 delete hoga
      int  ans2 = s2[j] + solveRec(s1,s2,i,j+1);

      ans = min(ans1,ans2);
    }
    return ans;
}
//Memoization
int solveMemo(string &s1, string &s2 , int i , int j,vector<vector<int>>&dp){
    //BASE CASE
    int ans = 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==s1.size() || j==s2.size()) {
        for(int k=i;k<s1.size();k++)  ans += s1[k];
        for(int k=j;k<s2.size();k++) ans += s2[k];
     }
     //dono same hai 
   else if(s1[i]==s2[j])  ans  =solveMemo(s1,s2,i+1,j+1,dp);
    else {
    // s1 delte hoga 
      int  ans1 = s1[i] + solveMemo(s1,s2,i+1,j,dp);
    //s2 delete hoga
      int  ans2 = s2[j] + solveMemo(s1,s2,i,j+1,dp);

      ans = min(ans1,ans2);
    }
    dp[i][j] = ans;
    return dp[i][j];
}

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        //Recursion
     // return  solveRec(s1,s2,0,0);

     //Memoization
     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
     return solveMemo(s1,s2,0,0,dp);


    }
};