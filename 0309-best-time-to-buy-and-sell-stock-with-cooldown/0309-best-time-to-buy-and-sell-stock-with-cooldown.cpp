class Solution {
public:

//RECURSION 
int solveRec(int i, int flag , vector<int>& prices){

    if(i >= prices.size()) return 0;

    int ans = 0;

    if(flag == 0 ) {
        int ans1 = -prices[i] + solveRec(i+1,1,prices);
    
        int ans2 = solveRec(i+1,flag,prices);
        ans = max(ans1,ans2);
    }

    else {
        int ans1 = prices[i] + solveRec(i+2,0,prices);

        int ans2 = solveRec(i+1,flag,prices);

        ans = max(ans1,ans2);
    }
   
    return ans;
}

//MEMOIZATION 

int solveMemo(int i, int flag , vector<int>& prices, vector<vector<int>>&dp){

    if(i >= prices.size()) return 0;

    if(dp[i][flag]!=-1) return dp[i][flag];

    int ans = 0;

    if(flag == 0 ) {
        int ans1 = -prices[i] + solveMemo(i+1,1,prices,dp);
    
        int ans2 = solveMemo(i+1,flag,prices,dp);
        ans = max(ans1,ans2);
    }

    else {
        int ans1 = prices[i] + solveMemo(i+2,0,prices,dp);

        int ans2 = solveMemo(i+1,flag,prices,dp);

        ans = max(ans1,ans2);
    }
   
    return dp[i][flag] = ans;
}

//TABULATION

int solveTab(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));

    for(int i=n-1;i>=0;i--){
        for(int flag=1;flag>=0;flag--){
              int ans = 0;

        if(flag == 0 ) {
        int ans1 = -prices[i] + dp[i+1][1];
    
        int ans2 = dp[i+1][flag];
        ans = max(ans1,ans2);
       }

       else {
        int ans1 = prices[i] + dp[i+2][0];

        int ans2 = dp[i+1][flag];

        ans = max(ans1,ans2);
      }
       dp[i][flag] = ans;
        }
    }
    return dp[0][0];
}

//SPACE OPTIMIZATION 
int solveSO(vector<int>& prices){

    int n = prices.size();
    vector<int>curr(2,0);
    vector<int>next1(2,0);
    vector<int>next2(2,0);


    for(int i=n-1;i>=0;i--){
        for(int flag=1;flag>=0;flag--){
              int ans = 0;

        if(flag == 0 ) {
        int ans1 = -prices[i] + next1[1];
    
        int ans2 = next1[flag];
        ans = max(ans1,ans2);
       }

       else {
        int ans1 = prices[i] + next2[0];

        int ans2 = next1[flag];

        ans = max(ans1,ans2);
      }
       curr[flag] = ans;
        }
        next2 = next1 ;
        next1 = curr;
    }
    return next1[0];
}




    int maxProfit(vector<int>& prices) {
        //RECURSION
        int n = prices.size();
       // return solveRec(0,0,prices); 
      
       //MEMOIZATION
       vector<vector<int>>dp(n+1,vector<int>(2,-1));
      // return solveMemo(0,0,prices,dp);

      //TABULATION
     // return solveTab(prices);

     //SPACE OPTIMIZATION
     return solveSO(prices);



    }
};