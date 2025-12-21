class Solution {
public:
//Recursion
int solveRec(string &s1,string &s2 , int i , int j){
    int cost = 0;
    //dono me se koi bhi khtm ho jaye to
    if(i==s1.size() || j==s2.size()){
        for(int x=i;x<s1.size();x++) cost += s1[x];
        for(int x=j;x<s2.size();x++) cost += s2[x];
    }
    // char match kr jaye
    else if (s1[i]==s2[j]) cost  = solveRec(s1,s2,i+1,j+1);

    // no match
    else {
        int cost1 = s1[i] + solveRec(s1,s2,i+1,j);
        int cost2 = s2[j] + solveRec(s1,s2,i,j+1);
        cost = min(cost1,cost2);
    }
    return cost;
}
//Memoization
int solveMemo(string &s1,string &s2 , int i , int j,vector<vector<int>>&dp){
    int cost = 0;
    //dono me se koi bhi khtm ho jaye to
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==s1.size() || j==s2.size()){
        for(int x=i;x<s1.size();x++) cost += s1[x];
        for(int x=j;x<s2.size();x++) cost += s2[x];
    }
    // char match kr jaye
    else if (s1[i]==s2[j]) cost  = solveMemo(s1,s2,i+1,j+1,dp);

    // no match
    else {
        int cost1 = s1[i] + solveMemo(s1,s2,i+1,j,dp);
        int cost2 = s2[j] + solveMemo(s1,s2,i,j+1,dp);
        cost = min(cost1,cost2);
    }
    dp[i][j] = cost;
    return dp[i][j];
}
//Tabulation
int solveTab(string &s1, string &s2){
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
    int temp = 0;
    for(int i=s2.size()-1;i>=0;i--){
        temp += s2[i];
       dp[s1.size()][i] = temp;
    }
    temp = 0;
     for(int i=s1.size()-1;i>=0;i--){
        temp += s1[i];
       dp[i][s2.size()] = temp;
    }
    
    for(int i=s1.size()-1;i>=0;i--){
        for(int j=s2.size()-1;j>=0;j--){
          int cost = 0;
        if (s1[i]==s2[j]) cost  = dp[i+1][j+1];
        else {
        int cost1 = s1[i] + dp[i+1][j];
        int cost2 = s2[j] +dp[i][j+1];
        cost = min(cost1,cost2);
        }
         dp[i][j] = cost;
        }
    }
return dp[0][0];
}


    int minimumDeleteSum(string s1, string s2) {
        //Recursion 
     // return   solveRec(s1,s2,0,0);

      //memoization
      vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
    //  return solveMemo(s1,s2,0,0,dp);

      // Tabulation
    return solveTab(s1,s2);

     

    }
};