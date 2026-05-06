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


    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //RECURSION 
    //   int ans  =  solveRec(0,amount,coins);

    //   if(ans==INT_MAX) return -1;
    //   return ans;

      // Memoization 

      vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans  =  solveMemo(0,amount,coins,dp);

      if(ans==INT_MAX) return -1;
      return ans;

    }
};