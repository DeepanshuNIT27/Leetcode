class Solution {
public:

//RECURSION .. COMPLEXITY (N*M * MIN(N,M)).
int solveRec(int i , int j , vector<int>& nums1, vector<int>& nums2){

    if(i == nums1.size() || j==nums2.size()) return 0;
    
    int ans = 0;
    if(nums1[i] == nums2[j]){
         ans  = 1 + solveRec(i+1,j+1,nums1,nums2);
    }
    else {
        ans  = 0;
    }
    return ans;
}
//MEMOIZATION 
int solveMemo(int i , int j , vector<int>& nums1, vector<int>& nums2, vector<vector<int>>&dp){

    if(i == nums1.size() || j==nums2.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans = 0;
    if(nums1[i] == nums2[j]){
         ans  = 1 + solveMemo(i+1,j+1,nums1,nums2,dp);
    }
    else {
        ans  = 0;
    }
    return  dp[i][j] = ans;
}


    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n  = nums1.size();
        int m = nums2.size();

        //RECURSION 
        //MEMOIZATION 
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans  = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               // ans  = max(ans,solveRec(i,j,nums1,nums2));
                ans  = max(ans,solveMemo(i,j,nums1,nums2,dp));
            }
        }
        return ans;
    }
};