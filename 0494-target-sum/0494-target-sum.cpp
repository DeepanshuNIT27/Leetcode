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


    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int s = accumulate(nums.begin(),nums.end(),0);
        int offset = s;
        //RECURSION 
       // return solveRec(0,0,target,nums);

       //Memoization 
     
       vector<vector<int>>dp(n+1,vector<int>(2*s + 1 ,-1));
       return solveMemo(0,0,target,nums,dp,offset);




        
    }
};