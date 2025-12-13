class Solution {
public:
//Method -2 grouping method
//RECURSION
int solveRec(vector<int>& stones , int i , int sum,int totalsum){
 if(i==stones.size()){
 int g1sum = sum;
 int g2sum = totalsum-sum;
 return abs(g1sum - g2sum);
}
int inc = solveRec(stones,i+1,sum+stones[i],totalsum);
int exc = solveRec(stones,i+1,sum,totalsum);
return min(inc,exc);
}
//MEMOIZATION
int solveMemo(vector<int>& stones , int i , int sum,int totalsum, vector<vector<int>>&dp){
 if(i==stones.size()){
 int g1sum = sum;
 int g2sum = totalsum-sum;
 return abs(g1sum - g2sum);
}
if(dp[i][sum]!=-1) return dp[i][sum];
int inc = solveMemo(stones,i+1,sum+stones[i],totalsum,dp);
int exc = solveMemo(stones,i+1,sum,totalsum,dp);
 dp[i][sum] = min(inc,exc);
 return dp[i][sum];
}

    int lastStoneWeightII(vector<int>& stones) {
      int totalsum = accumulate(stones.begin(),stones.end(),0);
      //Recursion
    //   return    solveRec(stones,0,0,totalsum);
    //Memoization
     vector<vector<int>>dp(stones.size()+1,vector<int>(totalsum+1,-1));
     return solveMemo(stones,0,0,totalsum,dp);

    }
};