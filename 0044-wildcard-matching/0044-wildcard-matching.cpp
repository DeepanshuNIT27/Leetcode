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

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        //recursive
       // return solveRec(s,p,0,0);

       //memorization
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       return solveMemo(s,p,0,0,dp);
        
    }
};