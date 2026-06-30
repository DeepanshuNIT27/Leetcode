class Solution {
public:
//OBSERTVATION QUE SUBPERSEQUENCE ME DONO STRING AS A SUBSEQUNCE MILNI CHAHIYE TO JO COMMON ELEMENTS HAI USKO 1 BAR BS RAKHENGE  SO LENGTH OF THE FINAL STRING IS  M + N - (LCS).

int solveTab(string str1, string str2 , vector<vector<int>>&dp){

    int m = str1.size();
    int n = str2.size();
    

    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){

            if(str1[i] == str2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else {
                dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
            }
            
    }
    }
    return dp[0][0];
}
    string shortestCommonSupersequence(string &str1, string &str2) {
        
        int m  = str1.size();
        int n = str2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        solveTab(str1,str2,dp);
        string ans = "";
      int i = 0;
      int j = 0;
        while(i<m && j<n){

            if(str1[i] == str2[j]){
                  ans += str1[i];
                  i++;j++;
            }
            else if(dp[i+1][j]>dp[i][j+1]){
                 ans += str1[i];
                 i++;
            }
            else{
                ans += str2[j];
                j++;
            }
        }
        while(i<m) {ans += str1[i]; i++;}
        while(j<n) {ans += str2[j] ; j++ ;}
        return ans;

    }
};