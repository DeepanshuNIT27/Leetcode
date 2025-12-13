class Solution {
public:
//Method 1
//REcursive soln 
 int solve(vector<int>& stones, int index , int sum){
    if(index == stones.size()){
        if(sum<0) return INT_MAX;
        return sum;
    }
    int pos = solve(stones,index+1, sum+stones[index]);
    int neg = solve(stones,index+1,sum-stones[index]);

    return min(pos,neg);
 }

 //Memoization
   int solveMemo(vector<int>& stones, int index , int sum,int totalsum,  vector<vector<int>>&dp){
    if(index == stones.size()){
        if(sum<0) return INT_MAX;
        return sum;
    }
    if(dp[index][sum+totalsum]!=-1) return dp[index][sum+totalsum];
    int pos = solveMemo(stones,index+1, sum+stones[index],totalsum,dp);
    int neg = solveMemo(stones,index+1,sum-stones[index],totalsum,dp);

    dp[index][sum+totalsum] = min(pos,neg);
    return dp[index][sum+totalsum];
 }
//Tabulation
  int solveTab(vector<int>& stones){
    int totalsum = accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>>dp(stones.size()+1,vector<int>(2*totalsum+1,-1));
    for(int sum =-totalsum ; sum<=totalsum;sum++){
        dp[stones.size()][sum+totalsum] = sum<0 ? INT_MAX : sum;
    }
    for(int i=stones.size()-1;i>=0;i--){
        for(int j=totalsum ;j>= -totalsum ;j--){
             int pos = INT_MAX ; int neg = INT_MAX;
            if(j+stones[i]<=totalsum)
              pos = dp[i+1][totalsum +j+stones[i]];
            if(j-stones[i]>=-totalsum)
              neg =  dp[i+1][totalsum +j-stones[i]];
             dp[i][j+totalsum] =  min(pos,neg);
        }

    }
    return dp[0][totalsum];
 }

    int lastStoneWeightII(vector<int>& stones) {
        //recursion
       //  return solve(stones,0,0);

        //Memoization
    //    int totalsum = accumulate(stones.begin(),stones.end(),0);
    //     vector<vector<int>>dp(stones.size()+1,vector<int>(2*totalsum+1,-1));
        // return solveMemo(stones,0,0,totalsum,dp);
        return solveTab(stones);

    }
};