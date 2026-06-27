class Solution {
public:
// RECURSION 
int solveRec(int i , int prev ,vector<int>& nums ){

    if(i>= nums.size()) return 0;
    
    int ans = 0;
    if(prev == -1 || nums[prev] < nums[i]){
        ans =  1 + solveRec(i+1,i,nums);
    }

    int ans2 = solveRec(i+1,prev,nums);

    return max(ans,ans2);
}

//MEMOIZATION 

int solveMemo(int i , int prev ,vector<int>& nums, vector<vector<int>>&dp ){

    if(i>= nums.size()) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    
    int ans = 0;
    if(prev == -1 || nums[prev] < nums[i]){
        ans =  1 + solveMemo(i+1,i,nums,dp);
    }

    int ans2 = solveMemo(i+1,prev,nums,dp);

    return  dp[i][prev+1] =  max(ans,ans2);
}


    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
        //RECURSION 
       // return solveRec(0,-1,nums);

       //MEMOIZATION 
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return solveMemo(0,-1,nums,dp);
    }
};