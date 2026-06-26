class Solution {
public:
//RECURSION 
int solveRec(int i , bool flag ,vector<int>& prices ){

    if(i == prices.size()) return 0;
    int ans = 0; 
    if(flag== false){
     //buy
     int  ans1  =   - prices[i]+ solveRec(i+1,true,prices);
      //skip
     int ans2 =     solveRec(i+1,flag,prices);
      ans =   max(ans1,ans2) ;
    }
    else {
        //sell
       int  ans1  = prices[i] + solveRec(i+1,false ,prices);
        //skip
      int   ans2  = solveRec(i+1,flag,prices);
       ans  =   max(ans1,ans2);

    }
    return ans;
}

// MEMOIZATION .

int solveMemo(int i , int flag ,vector<int>& prices, vector<vector<int>>&dp ){

    if(i == prices.size()) return 0;
    if(dp[i][flag] != -1) return dp[i][flag];
    int ans = 0; 
    if(flag==0){
     //buy
     int  ans1  =   - prices[i]+ solveMemo(i+1,1,prices,dp);
      //skip
     int ans2 =     solveMemo(i+1,flag,prices,dp);
      ans =   max(ans1,ans2) ;
    }
    else {
        //sell
       int  ans1  = prices[i] + solveMemo(i+1,0,prices,dp);
        //skip
      int   ans2  = solveMemo(i+1,flag,prices,dp);
       ans  =   max(ans1,ans2);

    }
    return dp[i][flag] = ans;
}

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //RECURSION 
 //return solveRec(0,false,prices);
     
     //MEMOIZATION 
     vector<vector<int>>dp(n+1,vector<int>(2,-1));
     return solveMemo(0,0,prices,dp);
        
    }
};