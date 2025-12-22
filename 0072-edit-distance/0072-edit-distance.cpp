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
    //Tabulation
    int solveTab(string &word1 , string &word2){
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
       for(int j=word2.size()-1;j>=0;j--) dp[word1.size()][j] = dp[word1.size()][j+1] +1 ;
        for(int i=word1.size()-1;i>=0;i--) dp[i][word2.size()] = dp[i+1][word2.size()] +1 ;
        for(int i=word1.size()-1;i>=0;i--){
            for(int j=word2.size()-1;j>=0;j--){
                 int cost = 0;
         if(word1[i]==word2[j])  cost = dp[i+1][j+1];
        else{
        //insert
        int  cost1 = 1 + dp[i][j+1];
        //delete
        int   cost2 = 1 + dp[i+1][j];

        //replace 
        int  cost3 = 1 + dp[i+1][j+1];
        cost = min(min(cost1,cost2),cost3);
       }
       dp[i][j] = cost;
            }
        }
return dp[0][0];
    }
    //Space optimization
    int solveSO(string &word1 , string &word2){
      int n = word1.size();
      int m = word2.size();
      vector<int>next(m+1,0), curr(m+1,0);
      //1 base case yha hai 
      for(int i=0;i<m;i++) next[i] = m-i;
        for(int i=n-1;i>=0;i--){
            //1 base case yha
            curr[m] = n-i;
            for(int j=m-1;j>=0;j--){
                 int cost = 0;
         if(word1[i]==word2[j])  cost = next[j+1];
        else{
        //insert
        int  cost1 = 1 + curr[j+1];
        //delete
        int   cost2 = 1 + next[j];

        //replace 
        int  cost3 = 1 + next[j+1];
        cost = min(min(cost1,cost2),cost3);
       }
       curr[j] = cost;
            }
            next = curr;
        }
return next[0];
    }

    int minDistance(string word1, string word2) {
        //Recursion
        //return solveRec(word1,word2,0,0);

        //Memoization
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
       // return solveMemo(word1,word2,0,0,dp);

       //Tabulation
       // return solveTab(word1,word2);

       //space optimization
       return solveSO(word1,word2);
    }
};