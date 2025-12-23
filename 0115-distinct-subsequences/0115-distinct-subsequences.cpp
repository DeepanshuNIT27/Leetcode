class Solution {
public:
//METHOD-2 OPTIMIZED METHOD
//Recursion
int solveRec(string&s, string&t, int i , int j){
    //Base case 
    if(j==t.size()) return 1;
    if(i==s.size())  return 0;
    int ans = 0;
    if(s[i]==t[j]){
        //dono bdhao
     ans += solveRec(s,t,i+1,j+1);
    }
    //i ko bs bdao
    ans += solveRec(s,t,i+1,j);
    return ans;
}
//Memoization
int solveMemo(string&s, string&t, int i , int j,vector<vector<int>>&dp){
    //Base case 
    if(j==t.size()) return 1;
    if(i==s.size())  return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = 0;
    if(s[i]==t[j]){
        //dono bdhao
     ans += solveMemo(s,t,i+1,j+1,dp);
    }
    //i ko bs bdao
    ans += solveMemo(s,t,i+1,j,dp);
    dp[i][j] = ans;
    return dp[i][j];
}
//Tabulation
int solveTab(string&s , string&t){
    vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
    for(int i=0;i<=s.size();i++) dp[i][t.size()] = 1;
    for(int i=s.size()-1;i>=0;i--){
        for(int j=t.size()-1;j>=0;j--){
            long long ans = 0LL;
           if(s[i]==t[j]){
            //dono bdhao
          ans += dp[i+1][j+1];
    }
           //i ko bs bdao
         ans += dp[i+1][j];
         dp[i][j] = ans;
        }
    }
 return dp[0][0];
}

    int numDistinct(string s, string t) {
        //recursion
       // return solveRec(s,t,0,0);

        //Memoization
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
      //  return solveMemo(s,t,0,0,dp);

        //Tabulation
        return solveTab(s,t);

    }
};