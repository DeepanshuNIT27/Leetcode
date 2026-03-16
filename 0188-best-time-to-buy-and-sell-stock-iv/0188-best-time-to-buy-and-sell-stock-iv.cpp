class Solution {
public:
// recursion 
int solveRec(vector<int>& prices ,int i , int buy , int limit){
    //Base case 
    if(limit == 0 || i == prices.size()) return 0 ;
    int profit = 0;
    if(buy){
      int buyItProfit = -prices[i] + solveRec(prices,i+1,0,limit);
      int skipIt  =  0 + solveRec(prices,i+1,buy,limit);
      profit = max(buyItProfit,skipIt);
    }

    else{
    int sellItProfit =  +prices[i] + solveRec(prices,i+1,1,limit-1);
    int skipIt = 0 + solveRec(prices,i+1,buy,limit);
    profit = max(sellItProfit,skipIt);
    }

    return profit;
}

//Memoization
int solveMemo(vector<int>& prices ,int i , int buy , int limit, vector<vector<vector<int>>>&dp){
    //Base case 
    if(limit == 0 || i == prices.size()) return 0 ;
    if( dp[i][buy][limit]!=-1) return  dp[i][buy][limit];
    int profit = 0;
    if(buy){
      int buyItProfit = -prices[i] + solveMemo(prices,i+1,0,limit,dp);
      int skipIt  =  0 + solveMemo(prices,i+1,buy,limit,dp);
      profit = max(buyItProfit,skipIt);
    }

    else{
    int sellItProfit =  +prices[i] + solveMemo(prices,i+1,1,limit-1,dp);
    int skipIt = 0 + solveMemo(prices,i+1,buy,limit,dp);
    profit = max(sellItProfit,skipIt);
    }

    dp[i][buy][limit] = profit;
    return dp[i][buy][limit];
}

// tabulation 
int solveTab(vector<int>& prices ,int i , int buy , int k, vector<vector<vector<int>>>&dp){
    int n = prices.size();
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            for(int limit=1;limit<=k;limit++){
                 int profit = 0;
                 if(buy){
              int buyItProfit = -prices[i] + dp[i+1][0][limit];
                 int skipIt  =  0 + dp[i+1][buy][limit];
                  profit = max(buyItProfit,skipIt);
                }

                 else{
          int sellItProfit =  +prices[i] + dp[i+1][1][limit-1];
          int skipIt = 0 + dp[i+1][buy][limit];
                  profit = max(sellItProfit,skipIt);
    }
            dp[i][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][k];

}

    int maxProfit(int k, vector<int>& prices) {
          int n  = prices.size();
      //  recursion 
        // return solveRec(prices,0,1,k);

         //Memoization
    //     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));

    //    return solveMemo(prices,0,1,k,dp);

      // tabulation 
      vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

     return solveTab(prices,0,1,k,dp);
    }
};