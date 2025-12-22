class Solution {
public:
//REcursion
    int solveRec(string &word1,string &word2, int i, int j){
        //BASE CASE
        if(i==word1.size()){
         return word2.size()-j;
        }
        if(j==word2.size()){
            return word1.size()-i;
        }
        //match
         int cost = 0;
        if(word1[i]==word2[j])  cost = solveRec(word1,word2,i+1,j+1);
       else{
        //insert
        int  cost1 = 1 + solveRec(word1,word2,i,j+1);
        //delete
        int   cost2 = 1 +solveRec(word1,word2,i+1,j);

        //replace 
        int  cost3 = 1 + solveRec(word1,word2,i+1,j+1);
        cost = min(min(cost1,cost2),cost3);
       }
        
        return cost;
    }
    //Memoization
    int solveMemo(string &word1,string &word2, int i, int j,vector<vector<int>>&dp){
        //BASE CASE
        if(i==word1.size()){
         return word2.size()-j;
        }
        if(j==word2.size()){
            return word1.size()-i;
        }
        //match
        if(dp[i][j]!=-1) return dp[i][j];
         int cost = 0;
        if(word1[i]==word2[j])  cost = solveMemo(word1,word2,i+1,j+1,dp);
       else{
        //insert
        int  cost1 = 1 + solveMemo(word1,word2,i,j+1,dp);
        //delete
        int   cost2 = 1 +solveMemo(word1,word2,i+1,j,dp);

        //replace 
        int  cost3 = 1 + solveMemo(word1,word2,i+1,j+1,dp);
        cost = min(min(cost1,cost2),cost3);
       }
        
        dp[i][j] = cost;
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        //Recursion
        //return solveRec(word1,word2,0,0);

        //Memoization
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size(),-1));
        return solveMemo(word1,word2,0,0,dp);
    }
};