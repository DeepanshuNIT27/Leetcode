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

//Tabulation 
bool solveTab(vector<int>& nums , int sum ){
   int n = nums.size();
   vector<vector<bool>>dp(nums.size()+1 , vector<bool>(sum+1,false));
   dp[n][0] = true;
  
   for(int i=n-1;i>=0;i--){
    for(int j=sum ;j>=0;j--){
   bool inc = false;
    if(j>=nums[i]) inc = dp[i+1][j-nums[i]];
    bool exc =  dp[i+1][j];

    dp[i][j] = inc || exc ;
    }
   }
 return   dp[0][sum];
}
// Solvespace optimization
bool solveSO(vector<int>& nums , int sum ){
   int n = nums.size();
  vector<bool>curr(sum+1,false);
  vector<bool>next(sum+1,false);
   next[0] = true;
  
   for(int i=n-1;i>=0;i--){
    for(int j=sum ;j>=0;j--){
    bool inc = false;
    if(j>=nums[i]) inc = next[j-nums[i]];
    bool exc =  next[j];

    curr[j] = inc || exc ;
    }
    next = curr;
   }
 return   next[sum];
}


    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;

       // return solveRec(0,sum/2,nums);
       int d = sum/2;
    //    vector<vector<int>>dp(nums.size()+1 , vector<int>(d+1,-1));
    //    return solveMemo(0,d,nums,dp);

        // Tabulation 
       // return solveTab(nums,d);

       //space optimization 
       return solveSO(nums,d);
    }
};