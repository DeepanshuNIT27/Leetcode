class Solution {
public:
//RECURSION 
int solveRec(int i , int j ,string &word1, string &word2 ){

    
     if(j == word2.size()) return word1.size()-i;
     if(i ==word1.size()) return word2.size()-j;
     
     int ans  = INT_MAX;
     if(word1[i] == word2[j] ){
        ans  =  solveRec(i+1,j+1,word1,word2);
     }
     else {
        //INSERT 
        int ans1 = 1 + solveRec(i,j+1,word1,word2);
        //DELETE
        int ans2  = 1 + solveRec(i+1,j,word1,word2);
        //REPLACE
        int ans3 = 1 + solveRec(i+1,j+1,word1,word2);

        ans  = min(ans , min(ans1,min(ans2,ans3)));
     }
     return ans;
}

//MEMOIZATION 
int solveMemo(int i , int j ,string &word1, string &word2, vector<vector<int>>&dp ){

    
     if(j == word2.size()) return word1.size()-i;
     if(i ==word1.size()) return word2.size()-j;

     if(dp[i][j]!=-1) return dp[i][j];
     
     int ans  = INT_MAX;
     if(word1[i] == word2[j] ){
        ans  =  solveMemo(i+1,j+1,word1,word2,dp);
     }
     else {
        //INSERT 
        int ans1 = 1 + solveMemo(i,j+1,word1,word2,dp);
        //DELETE
        int ans2  = 1 + solveMemo(i+1,j,word1,word2,dp);
        //REPLACE
        int ans3 = 1 + solveMemo(i+1,j+1,word1,word2,dp);

        ans  = min(ans , min(ans1,min(ans2,ans3)));
     }
     return dp[i][j] = ans;
}
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        //RECURSION 
       // return solveRec(0,0,word1,word2);

       //MEMOIZATION 
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       return solveMemo(0,0,word1,word2,dp);

    }
};