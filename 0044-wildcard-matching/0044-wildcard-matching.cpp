class Solution {
public:
//RECURSION 
bool solveRec(int i, int j , string &s, string &p){

    //BASE CASE 
    if(i == s.size()){
        while(j<p.size()){
            if(p[j]!='*') return false;
            j++;
        }
        return true;
    }
    if(j == p.size()){
       if(i != s.size()) return false;
       return true;
    }


    // MATCH AND '?' CASE
    bool ans = false;
    if(s[i] == p[j] || p[j] =='?'){
         ans  =  ans || solveRec(i+1,j+1,s,p);
    }
    else {
        if(p[j] == '*'){
            ans  = ans ||  solveRec(i+1,j,s,p);
            ans = ans || solveRec(i,j+1,s,p);
        }
        else {
            return false;
        }
    }
    return ans;
}

//MEMOIZATION 
bool solveMemo(int i, int j , string &s, string &p, vector<vector<int>>&dp){

    //BASE CASE 
    if(i == s.size() && j==p.size()) return dp[i][j] = true;
    if(i == s.size()){
        while(j<p.size()){
            if(p[j]!='*') return dp[i][j] =  false;
            j++;
        }
        return  dp[i][j] = true;
    }
    if(j == p.size()){
       return dp[i][j] = false;
    }
    if(dp[i][j]!=-1) return dp[i][j];


    // MATCH AND '?' CASE
    bool ans = false;
    if(s[i] == p[j] || p[j] =='?'){
         ans  =  ans || solveMemo(i+1,j+1,s,p,dp);
    }
    else {
        if(p[j] == '*'){
           bool  ans1  = solveMemo(i+1,j,s,p,dp);
           bool ans2 =  solveMemo(i,j+1,s,p,dp);

           ans  = ans1 || ans2;
        }
        else {
            return  dp[i][j] = false;
        }
    }
    return  dp[i][j] =  ans;
}

//TABULATION 
bool solveTab(string &s, string &p){
     int n = s.size();
     int m = p.size();

     vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
     dp[n][m] =  true;
    
   for(int j=m-1; j>=0; j--){
    if(p[j] == '*')
        dp[n][j] = dp[n][j+1];
    else
        dp[n][j] = false;
  }

     for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            bool ans = false;
         if(s[i] == p[j] || p[j] =='?'){
         ans  =  ans || dp[i+1][j+1];
         }
      else {
        if(p[j] == '*'){
           bool  ans1  = dp[i+1][j];
           bool ans2 =  dp[i][j+1];

           ans  = ans1 || ans2;
        }
        else {
            ans  = false;
        }
    }
     dp[i][j] =  ans;
        }
     }
return dp[0][0];
}

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        //RECURSION 
        //return solveRec(0,0,s,p);

        //MEMOIZATION 
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //return solveMemo(0,0,s,p,dp);

        //TABULATION 
        return solveTab(s,p);
    }
};