class Solution {
public:
  bool isSafe(vector<int>prev ,vector<int>curr){
  if(prev[0]<=curr[0] && prev[1]<=curr[1] && prev[2]<=curr[2]){
    return true;
  }
  else return false;

  return true;
  }
  //Using recursion
  int solveUsingRec(vector<vector<int>>& cuboids, int curr , int prev){
    //BASE CASE
    if(curr >= cuboids.size()) return 0;
     int inc = 0;
     if(prev == -1  || isSafe(cuboids[prev], cuboids[curr])){
        inc = cuboids[curr][2] + solveUsingRec(cuboids, curr+1 ,curr);
     }
      int exc = 0 + solveUsingRec(cuboids,curr+1,prev);

      return max(inc,exc);
  }

  //memo
  int solveUsingMemo(vector<vector<int>>& cuboids, int curr , int prev,vector<vector<int>>&dp){
    //BASE CASE
    if(curr >= cuboids.size()) return 0;
    if(dp[curr][prev+1]!= -1) return dp[curr][prev];
     int inc = 0;
     if(prev == -1  || isSafe(cuboids[prev], cuboids[curr])){
        inc = cuboids[curr][2] + solveUsingMemo(cuboids, curr+1 ,curr,dp);
     }
      int exc = 0 + solveUsingMemo(cuboids,curr+1,prev,dp);

      dp[curr][prev+1] = max(inc,exc);
      return dp[curr][prev+1];
  }
  // tabulation 

  int solveUsingTabu(vector<vector<int>>& cuboids){
     int n = cuboids.size();
     vector<vector<int>>dp(n+1, vector<int>(n+1,0));
    for(int curr = n-1;curr>=0 ;curr--){
        for(int prev = curr-1; prev>=-1;prev--){
         int inc = 0;
     if(prev == -1  || isSafe(cuboids[prev], cuboids[curr])){
        inc = cuboids[curr][2] + dp[curr+1][curr+1];
     }
      int exc = 0 +dp[curr+1][prev+1];

      dp[curr][prev+1] = max(inc,exc);
        }
    }
      return dp[0][0];
  }
  //space optimization
   int solveUsingTabuSO(vector<vector<int>>& cuboids){
     int n = cuboids.size();
     vector<int>currRow(n+1,0);
     vector<int>prevRow(n+1,0);
    for(int curr = n-1;curr>=0 ;curr--){
        for(int prev = curr-1; prev>=-1;prev--){
         int inc = 0;
     if(prev == -1  || isSafe(cuboids[prev], cuboids[curr])){
        inc = cuboids[curr][2] + prevRow[curr+1];
     }
      int exc = 0 +prevRow[prev+1];

      currRow[prev+1] = max(inc,exc);
        }
        prevRow = currRow;

    }
      return prevRow[0];
  }

  //space optimization 
   int solveUsingTabuSO2(vector<vector<int>>& cuboids){
     int n = cuboids.size();
     vector<int>currRow(n+1,0);
   
    for(int curr = n-1;curr>=0 ;curr--){
        for(int prev = -1; prev<=curr-1;prev++){
         int inc = 0;
     if(prev == -1  || isSafe(cuboids[prev], cuboids[curr])){
        inc = cuboids[curr][2] + currRow[curr+1];
     }
      int exc = 0 +currRow[prev+1];

      currRow[prev+1] = max(inc,exc);
        }

    }
      return currRow[0];
  }

    int maxHeight(vector<vector<int>>& cuboids) {
       
        for(auto & cuboid:cuboids){
            sort(cuboid.begin(),cuboid.end());
        }
        sort(cuboids.begin(),cuboids.end());
         int prev = -1;
        int curr = 0;
        //recursion
        // int ans = solveUsingRec(cuboids,curr,prev); //recursive call
        // return ans;

        //Memo
        int n = cuboids.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        // return solveUsingMemo(cuboids,curr,prev,dp);

        //tabulation
        // return solveUsingTabu(cuboids);

        //space optimization01
       // return solveUsingTabuSO(cuboids);

       // space optimization
       return solveUsingTabuSO(cuboids);



    }
};