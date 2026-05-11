class Solution {
public:

//RECURSION 
int solveRec(int i, int j , string&s){

    if(i==j || i-j==1) return 0;
    if(i>j) return 1000;

    int ans = INT_MAX;
    if(s[i]==s[j]){
      ans = solveRec(i+1,j-1,s);
    }
    else{
        ans = min(1 + solveRec(i+1,j,s) , 1+solveRec(i,j-1,s));
    }

    return ans ;
}
//MEMOIZATION 

int solveMemo(int i, int j , string&s,vector<vector<int>>&dp){

    if(i==j || i-j==1) return 0;
    if(i>j) return 1000;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = INT_MAX;
    if(s[i]==s[j]){
      ans = solveMemo(i+1,j-1,s,dp);
    }
    else{
        ans = min(1 + solveMemo(i+1,j,s,dp) , 1+solveMemo(i,j-1,s,dp));
    }

    return dp[i][j] =  ans ;
}



    int minInsertions(string s) {
        int i = 0;
        int j = s.size()-1;
        int n = s.size();
        //RECURSION 
       // return solveRec(i,j,s);

       //MEMOIZATION 
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return solveMemo(i,j,s,dp);
        
    }
};