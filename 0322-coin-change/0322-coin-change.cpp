class Solution {
public:
//recursion ka soln
// int solve(vector<int>& coins, int amount){
//     if(amount == 0){
//         return 0;
//     }
//     int mincoinsans= INT_MAX;
//     for(int i=0 ;i <coins.size();i++){
//         int coin= coins[i];
//         if(coin<=amount){
//          int recursionans = solve(coins, amount-coin);
//          if(recursionans!= INT_MAX){
//             int coinsused = 1+ recursionans;
//             mincoinsans = min(mincoinsans,coinsused);
//          }
//         }

//     }
//     return mincoinsans;
// }


//1.d dp hai
// int solveMemo(vector<int>& coins, int amount, vector<int>&dp){
//     if(amount == 0){
//         return 0;
//     }
//    if(dp[amount]!=-1) return dp[amount];
//     int mincoinsans= INT_MAX;
//     for(int i=0 ;i <coins.size();i++){
//         int coin= coins[i];
//         if(coin<=amount){
//          int recursionans = solveMemo(coins, amount-coin,dp);
//          if(recursionans!= INT_MAX){
//             int coinsused = 1+ recursionans;
//        //step->2
//             mincoinsans= min(mincoinsans,coinsused);
//          }
//         }

//     }
//     dp[amount] = mincoinsans;
//     return dp[amount];
// }

//2.D dp
int solveTabulation(vector<int>& coins, int amount){
    vector<int>dp(amount+1,-1);
    dp[0] = 0;
    // amount -> n->0
    //reverse 0->n
    for(int amt = 1; amt<=amount;amt++){
        int mincoinsans= INT_MAX;
    for(int i=0 ;i <coins.size();i++){
        int coin= coins[i];
        if(coin<=amt){
         int recursionans = dp[amt-coin];
         if(recursionans!= INT_MAX){
            int coinsused = 1+ recursionans;
            mincoinsans= min(mincoinsans,coinsused);
         }
    }
    }
     dp[amt] = mincoinsans;
    }
    
    return dp[amount];
}
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solve(coins,amount);
        // if(ans==INT_MAX){
        //     return -1;
        // }
        // else
        // return ans;
        //step ->1,
        //top-down approach
    //     int n = coins.size();
    //     vector<int>dp(amount+1,-1);
    //    int ans = solveMemo(coins,amount,dp);
    //     if(ans==INT_MAX){
    //         return -1;
    //     }
    //     else
    //     return ans;
    // }
    // tabulation method
    int n = coins.size();
       int ans = solveTabulation(coins,amount);
        if(ans==INT_MAX){
            return -1;
        }
        else
        return ans;
    }

};