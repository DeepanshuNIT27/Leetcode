class Solution {
public:
//Recursion 
int solveRec(vector<int>& prices, int i , bool flag){
    //Base case ;
    if(i==prices.size()) return 0;

    // sell
    int  ans1 = 0;
    int ans2 = 0;
    int ans3 = 0;
  if(flag )  ans1 =  prices[i]  + solveRec(prices,i+1,false);
    // buy 
  if(flag == false) ans2 = -prices[i] + solveRec(prices,i+1,true);
    // nothing to do 
     ans3 =  0 + solveRec(prices,i+1,flag);

    return max(max(ans1,ans2),ans3);
}

//Memoization
int  solveMemo(vector<int>& prices, int i ,int flag , vector<vector<int>>&dp){
    //Base case ;
    if(i==prices.size()) return 0;
     if(dp[i][flag]!=-1) return dp[i][flag];
    // sell

      int   ans1 = 0;
     int  ans2 = 0;
     int ans3 = 0;
  if(flag)  ans1 =  prices[i] + solveMemo(prices,i+1,false,dp);
    // buy 
  if(flag == false) ans2 = - prices[i] + solveMemo(prices,i+1,true,dp);
    // nothing to do 
     ans3 =  0 + solveMemo(prices,i+1,flag,dp);

    dp[i][flag] = max(max(ans1,ans2),ans3);
    return dp[i][flag];
}
// Tabulation 
int solveTab(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2,0));

    for(int i=n-1;i>=0;i--){
        for(int flag = 0;flag<=1;flag++){
     int   ans1 = 0;
     int  ans2 = 0;
     int ans3 = 0;
   if(flag)  ans1 =  prices[i] + dp[i+1][0];
    // buy 
   if(flag == false) ans2 = - prices[i] + dp[i+1][1];
    // nothing to do 
     ans3 =  0 + dp[i+1][flag];

    dp[i][flag] = max(max(ans1,ans2),ans3);
    }
    }
    return dp[0][0];

}

// space optimization
int solveSO(vector<int>& prices){
    int n = prices.size();
    vector<int>curr(2,0);
    vector<int>next(2,0);

    for(int i=n-1;i>=0;i--){
        for(int flag = 0;flag<=1;flag++){
     int   ans1 = 0;
     int  ans2 = 0;
     int ans3 = 0;
   if(flag)  ans1 =  prices[i] + next[0];
    // buy 
   if(flag == false) ans2 = - prices[i] + next[1];
    // nothing to do 
     ans3 =  0 + next[flag];

    curr[flag] = max(max(ans1,ans2),ans3);
    }
    next = curr;
    }
    return curr[0];

} 


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //recursion
     // return   solveRec(prices,0,false);

     //memoization
     vector<vector<int>>dp(n+1,vector<int>(2,-1));
     //return solveMemo(prices,0,false,dp);

     //tabulation
     //return solveTab(prices);

     //space optimization
     return solveSO(prices);


    }
};