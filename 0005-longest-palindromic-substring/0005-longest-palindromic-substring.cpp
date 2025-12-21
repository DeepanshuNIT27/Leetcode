class Solution {
public:
int start = 0; int length = 1;
bool  solveRec(string &s, int i , int j, vector<vector<int>>&dp){
    if(i>=j) return true;
    if(dp[i][j]!=-1) return dp[i][j];
    bool flag = false;
    if(s[i]==s[j]) flag =  solveRec(s,i+1,j-1,dp);
    if(flag){
         if(j-i+1 > length){
            length = j-i+1;
            start = i;
         }
    }
    dp[i][j] = flag;
    return dp[i][j];
}
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                bool t = solveRec(s,i,j,dp);
            }
        }
        return s.substr(start,length);
    }
};