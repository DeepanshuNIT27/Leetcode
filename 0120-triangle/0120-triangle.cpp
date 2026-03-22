class Solution {
public:
//Recursion 
int solveRec(int i , int j , vector<vector<int>>& triangle){
    //Base case
    if(i>= triangle.size()) return INT_MAX;
    if(i == triangle.size()-1) return triangle[i][j];

    int ans1 = solveRec(i+1,j,triangle);
    int ans2 = solveRec(i+1,j+1,triangle);

    return triangle[i][j] + min(ans1,ans2);
}

// Memoization 
int solveMemo(int i , int j , vector<vector<int>>& triangle, vector<vector<int>>&dp){
    //Base case
    if(i>= triangle.size()) return INT_MAX;
    if(i == triangle.size()-1) return triangle[i][j];
   if(dp[i][j]!=INT_MAX) return dp[i][j];
    int ans1 = solveMemo(i+1,j,triangle,dp);
    int ans2 = solveMemo(i+1,j+1,triangle,dp);

   dp[i][j] =  triangle[i][j] + min(ans1,ans2);
   return dp[i][j];
}


    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //Recursion
        //return solveRec(0,0,triangle);

       //Memoization 
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        return solveMemo(0,0,triangle,dp);
    }
};