class Solution {
public:

//RECURSION 
int solveRec(int i , int j ,vector<int>& cuts ){

    if( i+1 == j) return 0;

    int mini = 1e9;
    for(int k=i+1;k<j;k++){ 
       int step = cuts[j] - cuts[i] + solveRec(i,k,cuts) + solveRec(k,j,cuts);
       mini = min(mini,step);
    }
    return mini;
}
//MEMOIZATION 
int solveMemo(int i , int j ,vector<int>& cuts, vector<vector<int>>&dp ){

    if( i+1 == j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int mini = INT_MAX;
    for(int k=i+1;k<j;k++){ 
       int step = cuts[j] - cuts[i] + solveMemo(i,k,cuts,dp) + solveMemo(k,j,cuts,dp);
       mini = min(mini,step);
    }
    return  dp[i][j] = mini;
}
    int minCost(int n, vector<int>& cuts) {
       
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
         //RECURSION 
        //return solveRec(0,cuts.size()-1,cuts);

        //MEMOIZATION 
        int m = cuts.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return solveMemo(0,m-1,cuts,dp);

    }
};