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


    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        //RECURSION 
       // return solveRec(0,0,s,t);

       //MEMOIZATION 
       vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));
       return solveMemo(0,0,s,t,dp);
    }
};