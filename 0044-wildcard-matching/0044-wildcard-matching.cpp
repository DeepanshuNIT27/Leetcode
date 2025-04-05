class Solution {
public:
//recursive soln
  bool solveRec(string &s, string &p , int i, int j){
    if(i== s.length() && j== p.length()){
        //dono bahar nikl gye
        return true;
    }
    if(j == p.length()){
        //pattern khtm ho gya but string ni
        return false;
    }
    if( i == s.length()){
        for(int k=j ;k<p.length();k++){
            if(p[k] !='*'){
            return false;
            }
        }
        return true;
    }
    if(p[j] =='?' || s[i]==p[j]){
       return solveRec(s,p,i+1,j+1);
    }
    else if( p[j]=='*'){
     return solveRec(s,p,i+1,j) || solveRec(s,p,i,j+1);
    }
    else{
        return false;
    }
  return  false;
  }
  //memorization
   bool solveMemo(string &s, string &p , int i, int j,vector<vector<int>>&dp){
    if(i== s.length() && j== p.length()){
        //dono bahar nikl gye
        return true;
    }
    if(j == p.length()){
        //pattern khtm ho gya but string ni
        return false;
    }
    if( i == s.length()){
        for(int k=j ;k<p.length();k++){
            if(p[k] !='*'){
            return false;
            }
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];

     bool ans ;
    if(p[j] =='?' || s[i]==p[j]){
       ans =  solveMemo(s,p,i+1,j+1,dp);
    }
    else if( p[j]=='*'){
     ans =  solveMemo(s,p,i+1,j,dp) || solveMemo(s,p,i,j+1,dp);
    }
    else{
        ans = false;
    }
     dp[i][j] = ans;   
  return  dp[i][j];
  }
  //tabulation
  bool solveTab(string s, string p, int m,int n){
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    dp[m][n] = true;
   
   for(int col =0 ;col<n ;col++){
    bool flag = true;
        for(int k=col ;k<p.length();k++){
            if(p[k] !='*'){
            flag = false;
            break;
            }
        }
         dp[m][col] = flag;
    }


   for(int i=m-1;i>=0;i--){
    for(int j=n-1 ;j>=0 ;j--){
     bool ans ;
     if(p[j] =='?' || s[i]==p[j]){
       ans =  dp[i+1][j+1];
    }
    else if( p[j]=='*'){
     ans =  dp[i+1][j] || dp[i][j+1];
    }
    else{
        ans = false;
    }
     dp[i][j] = ans;   
    }
   }
  return  dp[0][0];
  }
//space opti
bool solveTabSO(string s, string p, int m,int n){
   vector<int>next(n+1,0);
   vector<int>curr(n+1,0);
    next[n] = true;
   
   for(int col =0 ;col<n ;col++){
    bool flag = true;
        for(int k=col ;k<p.length();k++){
            if(p[k] !='*'){
            flag = false;
            break;
            }
        }
         next[col] = flag;
    }


   for(int i=m-1;i>=0;i--){
    for(int j=n-1 ;j>=0 ;j--){
     bool ans ;
     if(p[j] =='?' || s[i]==p[j]){
       ans =  next[j+1];
    }
    else if( p[j]=='*'){
     ans =  next[j] || curr[j+1];
    }
    else{
        ans = false;
    }
     next[j] = ans;   
    }
    curr = next;
   }
  return  next[0];
  }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        //recursive
       // return solveRec(s,p,0,0);

       //memorization
    //    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //    return solveMemo(s,p,0,0,dp);

       //tabulation 
      return  solveTab(s,p,m,n);
        
    }
};