class Solution {
public:
//RECURSIVE SOLUTION
bool solve(vector<int>&nums , int target , int i){
    if(target<0 || i==nums.size()) return false;
    if(target ==0) return true;
    //include 
    bool inc =solve(nums, target-nums[i] ,i+1);
    bool exc = solve( nums ,target , i+1);

    return inc || exc ;
}
//2-D approach top-down
bool solveMemo(vector<int>&nums , int target , int i, vector<vector<int>>&dp){
    if(target<0 || i==nums.size()) return false;
    if(target ==0) return true;
    //include 
    if(dp[target][i]!= -1) return dp[target][i];
    bool inc =solveMemo(nums, target-nums[i] ,i+1,dp);
    bool exc = solveMemo( nums ,target , i+1,dp);

   dp[target][i] = inc || exc;
   return dp[target][i];
}
// tabulation 
bool solveTebu(vector<int>&nums , int target){
    int n = nums.size();
     vector<vector<bool>>dp(target+1,vector<bool>(n+1,0));
    for(int col=0;col<=nums.size() ;col++){
        dp[0][col] = true;
     }
   for(int t=1;t<=target;t++){
    for(int i = n-1 ;i>=0;i--){
    bool inc = 0;
    if(t-nums[i]>=0){
        inc = dp[t-nums[i]][i+1];
    }
    bool exc =  dp[t][i+1];

    dp[t][i] = inc || exc;
    }
   }
   return dp[target][0];
}
// space optimization01
bool solveTebuSO(vector<int>&nums , int target){
    int n = nums.size();
     
     vector<int>curr(target+1,0);
     vector<int>next(target+1,0);
    for(int col=0;col<=nums.size() ;col++){
       next[0] = true;
     }
      for(int i = n-1 ;i>=0;i--){
   for(int t=1;t<=target;t++){
   
    bool inc = 0;
    if(t-nums[i]>=0){
        inc = next[t-nums[i]];
    }
    bool exc =  next[t];

    curr[t] = inc || exc;
    }
    next = curr;
   }
   return next[target];
}
//space optimization -02
bool solveTebuSO2(vector<int>&nums , int target){
    int n = nums.size();
     
     vector<int>curr(target+1,0);
    
    for(int col=0;col<=nums.size() ;col++){
       curr[0] = true;
     }
      for(int i = n-1 ;i>=0;i--){
   for(int t=target;t>=1;t--){
   
    bool inc = 0;
    if(t-nums[i]>=0){
        inc = curr[t-nums[i]];
    }
    bool exc =  curr[t];

    curr[t] = inc || exc;
    }
   }
   return curr[target];
}

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
       int sum = accumulate(nums.begin(),nums.end(),0);
       if((sum%2) !=0) return false;
        int target = sum>>1;
        // recursion 
       // return solve(nums,target ,0);

        // top-downapproach
         int i = 0;
         vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
        // return solveMemo(nums,target,i,dp);

        //tabulation method
    //   return  solveTebu(nums,target);

    // space optimization
//   return   solveTebuSO(nums,target);
//space optimization-02
return solveTebuSO2(nums,target);
    }
};