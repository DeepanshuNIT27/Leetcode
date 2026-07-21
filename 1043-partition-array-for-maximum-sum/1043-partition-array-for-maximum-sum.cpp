class Solution {
public:
//RECURSION 
int solveRec(int i,vector<int>& arr, int k ){

    if(i >= arr.size()) return 0;

    int maxi = 0;
    int ans = 0;
    for(int j=0;j<k && i+j<arr.size();j++){
      
       maxi = max(maxi, arr[i+j]);
      int val = maxi*(j+1) + solveRec(i+j+1,arr,k);
      ans = max(ans,val);
    }
    return ans; 
}

//MEMOIZATION 
int solveMemo(int i,vector<int>& arr, int k, vector<int>&dp ){

    if(i >= arr.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int maxi = 0;
    int ans = 0;
    for(int j=0;j<k && i+j<arr.size();j++){
      
       maxi = max(maxi, arr[i+j]);
      int val = maxi*(j+1) + solveMemo(i+j+1,arr,k,dp);
      ans = max(ans,val);
    }
    return dp[i] = ans; 
}

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        //RECURSION 
       // return solveRec(0,arr,k);

       //MEMOIZATION 
       vector<int>dp(n+1,-1);
       return solveMemo(0,arr,k,dp);
    }
};