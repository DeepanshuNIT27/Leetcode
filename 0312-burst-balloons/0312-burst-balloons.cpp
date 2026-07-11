class Solution {
public:
//RECURSION 
int solveRec(int i, int j ,vector<int>& nums ){

    if(i+1 == j ) return 0;

    int maxi = 0;
    for(int k=i+1;k<j;k++){

        int step = nums[i]*nums[k]*nums[j] + solveRec(i,k,nums) + solveRec(k,j,nums);

        maxi = max(maxi,step);
    }
    return maxi;
}
//MEMOIZATION

int solveMemo(int i, int j ,vector<int>& nums, vector<vector<int>>&dp ){

    if(i+1 == j ) return  dp[i][j] = 0;
    if(dp[i][j]!=-1) return  dp[i][j];

    int maxi = 0;
    for(int k=i+1;k<j;k++){

        int step = nums[i]*nums[k]*nums[j] + solveMemo(i,k,nums,dp) + solveMemo(k,j,nums,dp);

        maxi = max(maxi,step);
    }
    return  dp[i][j] = maxi;
}

//TABULATION 
int solveTab(vector<int>& nums){
   int n = nums.size();
vector<vector<int>>dp(n,vector<int>(n,0));

 for(int i=n-1;i>=0;i--){
    for(int j=i+2;j<n;j++){
         int maxi = 0;
       for(int k=i+1;k<j;k++){

        int step = nums[i]*nums[k]*nums[j] + dp[i][k] + dp[k][j];

        maxi = max(maxi,step);
    }
        dp[i][j] = maxi;
    }
 }
 return dp[0][n-1];

}

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();

        //RECURSION 
       // return solveRec(0,n-1,nums);

       //MEMOIZATION  
       vector<vector<int>>dp(n,vector<int>(n,-1));
       //return solveMemo(0,n-1,nums,dp);

       //TABULATION
       return solveTab(nums);

    }
};