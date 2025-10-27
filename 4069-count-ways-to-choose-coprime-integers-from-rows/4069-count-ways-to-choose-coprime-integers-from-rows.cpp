class Solution {
public:
const long long MOD = 1e9 + 7;
//Recursion
int solveRec(int i , int gcd , vector<vector<int>>& mat ){
    int m = mat.size();
    int n = mat[0].size();
    //BASE CASE
    if(i==m){
        if(gcd==1) return 1;
        else return 0;
    }
   int ans = 0;
    for(int j=0;j<n;j++){
        if(i!=0){
       ans += solveRec(i+1 , __gcd(gcd,mat[i][j]),mat);
        }
        else  ans+= solveRec(i+1,mat[i][j],mat); 
    }
    return ans;
}
// Memoization
int solveMemo(int i , int gcd ,vector<vector<int>>& mat , vector<vector<int>>&dp){
     int m = mat.size();
     int n = mat[0].size();
     //BASE CASE
    if(i==m){
        if(gcd==1) return 1;
        else return 0;
    }
    if(dp[i][gcd]!=-1) return dp[i][gcd];
   int ans = 0;
    for(int j=0;j<n;j++){
       ans = (ans + solveMemo(i+1 , __gcd(gcd,mat[i][j]),mat,dp))%MOD;
    }
    dp[i][gcd] = ans;
    return dp[i][gcd];

}

    int countCoprime(vector<vector<int>>& mat) {
    // recusrsion call
    // return solveRec(0,-1,mat);
    // memoization 
    vector<vector<int>>dp(152,vector<int>(152,-1));
    return solveMemo(0,0,mat,dp);
    }
};