class Solution {
public:

//RECURSION 
int solveRec(int i , int sum , int &target , vector<int>& nums){

    if(i>=nums.size()) {
        if(sum == target) return 1;
        return 0;
    }

    int add = solveRec(i+1, sum+nums[i], target , nums);
    int sub = solveRec(i+1,sum - nums[i] , target, nums);

    return add + sub ;
}

//MEMOIZATION 
int solveMemo(int i , int sum , int &target , vector<int>& nums,vector<vector<int>>&dp , int offset){

    if(i>=nums.size()) {
        if(sum == target) return 1;
        return 0;
    }
    if(dp[i][sum+offset]!=-1) return dp[i][sum+offset];

    int add = solveMemo(i+1, sum+nums[i], target , nums,dp,offset);
    int sub = solveMemo(i+1,sum - nums[i] , target, nums,dp,offset);

    return  dp[i][sum+offset]  = add + sub ;
}

// Tabulation 

int solveTab(vector<int>& nums , int target , vector<vector<int>>&dp , int &offset ){
    int n = nums.size();
  int S = offset;
   dp[n][target+offset] = 1;
    for(int i=n-1;i>=0;i--){
        for(int sum = -S ; sum<=S;sum++){

            int add  = 0 ;
            int sub  = 0;

          if(sum + nums[i] <= S && sum + nums[i] >= -S)  add = dp[i+1][sum+nums[i]+offset];
           if(sum - nums[i] <= S && sum - nums[i] >= -S)sub = dp[i+1][sum-nums[i]+offset];

            dp[i][sum+offset]  = add + sub ;

        }
    }

    return dp[0][offset];
}

//Space optimization 

int solveSO(vector<int>& nums , int target  , int &offset ){
    vector<int>curr(2*offset+1);
    vector<int>next(2*offset+1);
    int n = nums.size();
    int S = offset;
   next[target+offset] = 1;
    for(int i=n-1;i>=0;i--){
        for(int sum = -S ; sum<=S;sum++){

            int add  = 0 ;
            int sub  = 0;

          if(sum + nums[i] <= S && sum + nums[i] >= -S)  add = next[sum+nums[i]+offset];
           if(sum - nums[i] <= S && sum - nums[i] >= -S)sub = next[sum-nums[i]+offset];

           curr[sum+offset]  = add + sub ;

        }
        next = curr;
    }

    return next[offset];
}





    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int s = accumulate(nums.begin(),nums.end(),0);
        if(abs(target) > s) return 0;
        int offset = s;
        //RECURSION 
       // return solveRec(0,0,target,nums);

       //Memoization 
     
    //    vector<vector<int>>dp(n+1,vector<int>(2*s + 1 ,-1));
    //    return solveMemo(0,0,target,nums,dp,offset);

    // Tabulation 
     
    //  vector<vector<int>>dp(n+1,vector<int>(2*s + 1 ,0));
    //  return solveTab(nums,target, dp , offset);

    // Space optimization 
   
    return solveSO(nums,target,offset);





        
    }
};