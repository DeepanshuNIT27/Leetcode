class Solution {
public:

//RECURSION 
int solveRec(int i , int amount ,vector<int>& coins){

    if(amount<0) return 0;

    if(i>=coins.size()) {
        if(amount == 0) return 1;
        return 0;
    }

    int inc = solveRec(i,amount-coins[i],coins);
    int exc = solveRec(i+1,amount,coins);

    return inc + exc ;
}

//Memoization 

int solveMemo(int i , int amount ,vector<int>& coins, vector<vector<int>>&dp){

    if(amount<0) return 0;

    if(i>=coins.size()) {
        if(amount == 0) return 1;
        return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];

    int inc = solveMemo(i,amount-coins[i],coins,dp);
    int exc = solveMemo(i+1,amount,coins,dp);

    dp[i][amount] = inc + exc ;
    return dp[i][amount];
}


    int change(int amount, vector<int>& coins) {
        int n  = coins.size();
        //RECURSION 
       // return solveRec(0,amount,coins);

       //Memoization 
       vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
       return solveMemo(0,amount,coins,dp);

        
    }
};