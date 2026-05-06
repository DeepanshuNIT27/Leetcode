class Solution {
public:

//RECURSION 
int solveRec(int i , int amount , vector<int>& coins ){

   if(amount == 0) return 0;
   if(i>= coins.size() || amount<0) return INT_MAX;

    int inc = solveRec(i,amount-coins[i],coins);
    if(inc!=INT_MAX) inc += 1;
    int exc = solveRec(i+1,amount,coins);

    return min(inc,exc);

}

//MEMOIZATION 

int solveMemo(int i , int amount , vector<int>& coins ,vector<vector<int>>&dp){

   if(amount == 0) return 0;
   if(i>= coins.size() || amount<0) return INT_MAX;

   if(dp[i][amount]!=-1) return dp[i][amount];

    int inc = solveMemo(i,amount-coins[i],coins,dp);
    if(inc!=INT_MAX) inc += 1;
    int exc = solveMemo(i+1,amount,coins,dp);

    return  dp[i][amount] =  min(inc,exc);

}

// Tabulation 

int solveTab(vector<int>& coins, int amount){

    int n = coins.size();
    vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX));
    for(int i = 0; i <= n; i++) dp[i][0] = 0;

    for(int i=n-1;i>=0;i--){
        for(int j =0; j<=amount;j++){
          
          int inc = INT_MAX;
           if(j - coins[i] >=0) inc = dp[i][j - coins[i]];
            if(inc!=INT_MAX) inc += 1;
            int exc = dp[i+1][j];

            dp[i][j] = min(inc,exc);
        }
    }
    return dp[0][amount];
}

// space optimization 

int solveSO(vector<int>& coins, int amount){

    int n = coins.size();
   vector<int>next(amount+1,INT_MAX);
   next[0] = 0;
    for(int i=n-1;i>=0;i--){
         vector<int>curr(amount+1,INT_MAX);
         curr[0] = 0;
        for(int j =0; j<=amount;j++){
          
          int inc = INT_MAX;
           if(j - coins[i] >=0) inc = curr[j - coins[i]];
            if(inc!=INT_MAX) inc += 1;
            int exc = next[j];

            curr[j] = min(inc,exc);
        }
        next = curr;
    }
    return next[amount];
}


    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //RECURSION 
    //   int ans  =  solveRec(0,amount,coins);

    //   if(ans==INT_MAX) return -1;
    //   return ans;

      // Memoization 

    //   vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
    //     int ans  =  solveMemo(0,amount,coins,dp);

    //   if(ans==INT_MAX) return -1;
    //   return ans;

    // Tabulation 
    //  int ans  =  solveTab(coins,amount);

    //   if(ans==INT_MAX) return -1;
    //   return ans;

    //Space optimization 

     int ans  =  solveSO(coins,amount);

      if(ans==INT_MAX) return -1;
      return ans;

    }
};