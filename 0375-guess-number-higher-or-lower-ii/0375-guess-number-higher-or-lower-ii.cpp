class Solution {
public:
//RECURSIVE SOLUTION
int solveUsingRec(int s,int e){
    //base case
    if(s>=e){
        return 0;
    }
    int ans = INT_MAX;
    for(int i =s;i<= e;i++){
        ans = min(ans,i+max(solveUsingRec(s,i-1),solveUsingRec(i+1,e)));
    }
    return ans;
}
//MEMO
int solveUsingMemo(int s,int e,vector<vector<int>>&dp){
    //base case
    if(s>=e){
        return 0;
    }
    if(dp[s][e]!= -1) return dp[s][e];
    int ans = INT_MAX;
    for(int i =s;i<= e;i++){
        ans = min(ans,i+max(solveUsingMemo(s,i-1,dp),solveUsingMemo(i+1,e,dp)));
    }
     dp[s][e] = ans;
    return dp[s][e];
}
    int getMoneyAmount(int n) {
       // RECURSION
        // int ans = solveUsingRec(1,n);
        // return ans;

        //Memo
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveUsingMemo(1,n,dp);
    }
};