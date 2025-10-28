class Solution {
public:
//RECURSION
bool solveRec(string &s , string &p , int i , int j){
    //BASE CASE
    if(i == s.size() && j == p.size()) {
         return true;
    }
    if(j>=p.size()){
        return false;
    }
    //3rd case lene ki jarurat ni hai multiple * wala vo case bnega hi ni 

    bool currmatch = ( i<s.size() && ((s[i]==p[j]) || (p[j]=='.')));
    if(j+1<p.size() && p[j+1]=='*'){
         bool EmptyWala = solveRec(s,p,i,j+2);
         bool PreElementWala = currmatch &&  solveRec(s,p,i+1,j);
         return  EmptyWala || PreElementWala;
    }
    else if(currmatch){
        return solveRec(s,p,i+1,j+1);
    }
    else {
        return false;
    }
   
}
//MEMOIZATION
bool solveMemo(string &s , string &p , int i , int j, vector<vector<int>>&dp){
    //BASE CASE
    if(i == s.size() && j == p.size()) {
         return true;
    }
    if(j>=p.size()){
        return false;
    }

    //3rd case lene ki jarurat ni hai multiple * wala vo case bnega hi ni 
    if(dp[i][j]!=-1) return dp[i][j];
    bool ans ;
    bool currmatch = ( i<s.size() && ((s[i]==p[j]) || (p[j]=='.')));
    if(j+1<p.size() && p[j+1]=='*'){
         bool EmptyWala = solveMemo(s,p,i,j+2,dp);
         bool PreElementWala = currmatch &&  solveMemo(s,p,i+1,j,dp);
         ans =  EmptyWala || PreElementWala;
    }
    else if(currmatch){
         ans = solveMemo(s,p,i+1,j+1,dp);
    }
    else {
        ans =  false;
    }
 dp[i][j] = ans;
   return dp[i][j];
}
//TABULATION METHOD
bool solveTab(string &s , string &p , int n , int m){
     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //BASE CASE
    dp[n][m] = true;
  
    for(int i=n;i>=0;i--){
        for(int j=m-1;j>=0;j--){
    bool currmatch = ( i<s.size() && ((s[i]==p[j]) || (p[j]=='.')));
    bool ans ;
    if(j+1<p.size() && p[j+1]=='*'){
         bool EmptyWala = dp[i][j+2];
         bool PreElementWala = currmatch &&  dp[i+1][j];
         ans =  EmptyWala || PreElementWala;
    }
    else if(currmatch){
         ans = dp[i+1][j+1];
    }
    else {
        ans =  false;
    }
 dp[i][j] = ans;
   
        }
    }
    return dp[0][0];
}
//SPACE OPTIMIZATION
bool solveTabSo(string &s , string &p , int n , int m){
   vector<int>curr(m+1,0);
   vector<int>next(m+1,0);
    //BASE CASE
    next[m] = true;
  
    for(int i=n;i>=0;i--){
        if(i==n) curr[m] = true;
        else curr[m] = false;
        for(int j=m-1;j>=0;j--){
    bool currmatch = ( i<s.size() && ((s[i]==p[j]) || (p[j]=='.')));
    bool ans ;
    if(j+1<p.size() && p[j+1]=='*'){
         bool EmptyWala = curr[j+2];
         bool PreElementWala = currmatch &&  next[j];
         ans =  EmptyWala || PreElementWala;
    }
    else if(currmatch){
         ans = next[j+1];
    }
    else {
        ans =  false;
    }
 curr[j] = ans;
   
        }
        next = curr;
    }
    return next[0];
}

    bool isMatch(string s, string p) {
        //RECURSION
        //return solveRec(s,p,0,0);

        //MEMOIZATION
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       // return solveMemo(s,p,0,0,dp);
       
       //TABULATION METHOD 
  //return solveTab(s,p,n,m);

  //SPACE OPTIMIZATION
  return solveTabSo(s,p,n,m);

    }
};