class Solution {
public:
// THIS QUE IS SAME AS PREVIOUS ESME BS 2 KI JAGAH K LIMIT HAI .
//RECURSION 

int solveRec(int i , int flag , int trans , vector<int>& prices){

    if(i == prices.size() || trans == 0) return  0 ;
    
    int ans = 0;
    if(flag ==0 ) {

        int ans1 = -prices[i] + solveRec(i+1,1,trans,prices);
        int ans2 = solveRec(i+1,flag,trans,prices);

        ans = max(ans1,ans2);
    }
    else {

        int ans1 = prices[i] + solveRec(i+1,0,trans-1,prices);
        int ans2 = solveRec(i+1,flag,trans,prices);

        ans = max(ans1,ans2);
    }

    return  ans;
}

// MEMOIZATION 

int solveMemo(int i , int flag , int trans , vector<int>& prices, vector<vector<vector<int>>>&dp){

    if(i == prices.size() || trans == 0) return  0 ;
    if(dp[i][flag][trans]!=-1 ) return dp[i][flag][trans];
    
    int ans = 0;
    if(flag ==0 ) {

        int ans1 = -prices[i] + solveMemo(i+1,1,trans,prices,dp);
        int ans2 = solveMemo(i+1,flag,trans,prices,dp);

        ans = max(ans1,ans2);
    }
    else {

        int ans1 = prices[i] + solveMemo(i+1,0,trans-1,prices,dp);
        int ans2 = solveMemo(i+1,flag,trans,prices,dp);

        ans = max(ans1,ans2);
    }

    return dp[i][flag][trans] = ans;
}

    int maxProfit(int k, vector<int>& prices) {
        
          int  n = prices.size();
        
        //RECURSION 
      //  return solveRec(0,0,k,prices);

       // MEMOIZATION 
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));

        return solveMemo(0,0,k,prices,dp);
    }
};