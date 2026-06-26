class Solution {
public:
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

//TABULATION 
int solveTab(vector<int>& prices){
     int  n = prices.size();
      vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

      for(int i=n-1;i>=0;i--){
        for(int flag=1;flag>=0;flag--){
            for(int trans=2;trans>0;trans--){
                int ans = 0;
            if(flag ==0 ) {

        int ans1 = -prices[i] + dp[i+1][1][trans];
        int ans2 = dp[i+1][flag][trans];

        ans = max(ans1,ans2);
        }
         else {

        int ans1 = prices[i] + dp[i+1][0][trans-1];
        int ans2 = dp[i+1][flag][trans];

        ans = max(ans1,ans2);
    }
    dp[i][flag][trans] = ans;
            }
        }
      
      }
      return dp[0][0][2];

}
//SPACE OPTIMIZATION 

int solveSO(vector<int>& prices){
     int  n = prices.size();
      vector<vector<vector<int>>>dp(2,vector<vector<int>>(2,vector<int>(3,0)));

      for(int i=n-1;i>=0;i--){
        for(int flag=1;flag>=0;flag--){
            for(int trans=2;trans>0;trans--){
                int ans = 0;
            if(flag ==0 ) {

        int ans1 = -prices[i] + dp[1][1][trans];
        int ans2 = dp[1][flag][trans];

        ans = max(ans1,ans2);
        }
         else {

        int ans1 = prices[i] + dp[1][0][trans-1];
        int ans2 = dp[1][flag][trans];

        ans = max(ans1,ans2);
    }
    dp[0][flag][trans] = ans;
            }
        }
        dp[1] = dp[0];
      
      }
      return dp[0][0][2];

}



    int maxProfit(vector<int>& prices) {
        int  n = prices.size();
        
        //RECURSION 
        //return solveRec(0,0,2,prices);
      
      //MEMOIZATION 
      //  vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));

       // return solveMemo(0,0,2,prices,dp);

       //TABULATION 
       //return solveTab(prices);

       // SPACE OPTIMIZATION 
       return solveSO(prices);


    }
};