class Solution {
public:

//RECURSION
// int solve(vector<int>&nums ,int n ,int i){
//     if(i>=n){
//         return 0;
//     }
//     int includes =  nums[i] +solve(nums,n,i+2);
//     int excludes =   0 + solve(nums ,n , i+1) ;
//     int maxi = max(includes ,excludes);
//     return maxi;
// }

// using dp top-down 
int solveTopDown(vector<int>&nums ,int n ,int i,vector<int>&dp){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    int includes =  nums[i] +solveTopDown(nums,n,i+2,dp);
    int excludes =   0 + solveTopDown(nums ,n , i+1,dp) ;
    dp[i] = max(includes ,excludes);
    return dp[i];
}
//using bottom-up approach
int solvetabultion(vector<int>&nums){
    int n = nums.size();
    vector<int>dp(n+20,0);
   //0->n
   //n->0
   for(int i=n-1;i>=0;i--){
    int includes =  nums[i] +dp[i+2];
    int excludes =   0 + dp[i+1] ;
    dp[i] = max(includes ,excludes);
   }
    return dp[0];
   
}


    int rob(vector<int>& nums) {
    int n = nums.size();
//     int i = 0;
//    int ans =  solve(nums,n,i);
//    return ans;

//1-d dp
    // vector<int>dp(n+1,-1);
    // return solveTopDown(nums,n,0,dp);
    // }

    //tabulation;
    return solvetabultion(nums);

    }
};