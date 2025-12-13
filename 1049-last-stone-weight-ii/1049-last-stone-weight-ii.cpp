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


    int lastStoneWeightII(vector<int>& stones) {
        //recursion
       //  return solve(stones,0,0);

        //Memoization
       int totalsum = accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>>dp(stones.size()+1,vector<int>(2*totalsum+1,-1));
        return solveMemo(stones,0,0,totalsum,dp);

    }
};