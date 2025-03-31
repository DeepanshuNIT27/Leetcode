class Solution {
public:
  int solveUsingRec(string text1, string text2 , int i ,int j){
    //BASE CASE
    if(i>= text1.size() || j>= text2.size()) return 0;
     int ans = 0;
    //MATCH
    if(text1[i] == text2[j]){
        ans = 1 + solveUsingRec(text1,text2,i+1,j+1);
    }
    //NOT
    else{
        ans = 0 + max(solveUsingRec(text1,text2,i+1,j) ,solveUsingRec(text1,text2,i,j+1));
    }
    return ans;
  }
  //2d dp Memo
  int solveUsingMemo(string &text1, string &text2 , int i ,int j,vector<vector<int>>&dp){
    //yha text ko by reference pass krna ni to tle milega q ki copy bahut bn jayegi n

    //BASE CASE
    if(i>= text1.size() || j>= text2.size()) return 0;

    if(dp[i][j]!= -1) return dp[i][j];
     int ans = 0;
    //MATCH
    if(text1[i] == text2[j]){
        ans = 1 + solveUsingMemo(text1,text2,i+1,j+1,dp);
       
    }
    //NOT
    else{
        ans = 0 + max(solveUsingMemo(text1,text2,i+1,j,dp) ,solveUsingMemo(text1,text2,i,j+1,dp));
       
    }
    dp[i][j] = ans;
    return dp[i][j];
  }

// tabulation
int solveUsingTab(string &text1, string &text2){
    //yha text ko by reference pass krna ni to tle milega q ki copy bahut bn jayegi n
    vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
    //yha flow ko reverse krte hai
    for(int i=text1.size()-1 ;i>=0 ;i--){
        for(int j=text2.size()-1;j>=0;j--){
         int ans = 0;
        if(text1[i] == text2[j]){
        ans = 1 + dp[i+1][j+1];
       
    }
    else{
        ans = 0 + max(dp[i+1][j] ,dp[i][j+1]);
       
    }
    dp[i][j] = ans;
        }
    }
    return dp[0][0];
  }
  //space optimization
  int solveUsingTabSO(string &text1, string &text2){
    //yha text ko by reference pass krna ni to tle milega q ki copy bahut bn jayegi n
    vector<int>prev(text2.size()+1,0);
    vector<int>curr(text2.size()+1,0);

    //yha flow ko reverse krte hai
    for(int i=text1.size()-1 ;i>=0 ;i--){
        for(int j=text2.size()-1;j>=0;j--){
         int ans = 0;
        if(text1[i] == text2[j]){
        ans = 1 + prev[j+1];
       
    }
    else{
        ans = 0 + max(prev[j] ,curr[j+1]);
       
    }
    curr[j] = ans;
        }
        prev = curr;
    }
    return prev[0];
  }

    int longestCommonSubsequence(string text1, string text2) {
        //recursion
        int i =0;
        int j= 0;
        // return solveUsingRec(text1,text2,i,j);

        // Memo
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //   return  solveUsingMemo(text1,text2,i,j,dp);

      // tabulation
    //  return  solveUsingTab(text1,text2);

      // space optimization
      return solveUsingTabSO(text1,text2);


    }
};