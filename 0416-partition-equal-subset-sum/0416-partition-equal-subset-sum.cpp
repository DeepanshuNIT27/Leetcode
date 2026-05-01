class Solution {
public:
//Recursion 
bool solveRec(int i , int sum ,vector<int>& nums){
    //Base case
    if(i>=nums.size()){
        if(sum == 0) return true;
        else return false;
    }

    bool inc = solveRec(i+1,sum-nums[i],nums);
    bool exc = solveRec(i+1,sum,nums);

    return inc || exc ;
}

// Memoization 
bool solveMemo(int i , int sum ,vector<int>& nums,vector<vector<int>>&dp){
    //Base case
    if(sum<0) return false;
    if(i>=nums.size()){
        if(sum == 0) return true;
        else return false;
    }
   if(dp[i][sum]!=-1) return dp[i][sum];
    bool inc = solveMemo(i+1,sum-nums[i],nums,dp);
    bool exc = solveMemo(i+1,sum,nums,dp);

    return dp[i][sum] = inc || exc ;
}


    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;

       // return solveRec(0,sum/2,nums);
       int d = sum/2;
       vector<vector<int>>dp(nums.size()+1 , vector<int>(d+1,-1));
       return solveMemo(0,d,nums,dp);
    }
};