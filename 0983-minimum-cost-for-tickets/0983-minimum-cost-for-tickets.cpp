class Solution {
public:
//RECURSIVE SOLUTION
int solveRec(vector<int>& days,vector<int>& costs,int i){
    //BASE CASE
    if(i>=days.size()) return 0;
    //1 day pass leke dekho

    int cost1 = costs[0] + solveRec(days,costs,i+1);

    //7 days ka leke dekho
    int passday = days[i] + 7 - 1;
    int j = i;
    while(j<days.size()  && days[j]<=passday){
        j++;
    }
    int cost7 = costs[1] + solveRec(days,costs,j);

    //30 days ka leke dekho
    passday = days[i] + 30 - 1;
    j = i;
    while(j<days.size()  && days[j]<=passday){
        j++;
    }
    int cost30 = costs[2] + solveRec(days,costs,j);

    return min(cost1 , min(cost7,cost30));
    
}
//MEMOIZATION
int solveMemo(vector<int>& days,vector<int>& costs,int i,vector<int>&dp){
    //BASE CASE
    if(i>=days.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    //1 day pass leke dekho

    int cost1 = costs[0] + solveMemo(days,costs,i+1,dp);

    //7 days ka leke dekho
    int passday = days[i] + 7 - 1;
    int j = i;
    while(j<days.size()  && days[j]<=passday){
        j++;
    }
    int cost7 = costs[1] +solveMemo(days,costs,j,dp);

    //30 days ka leke dekho
    passday = days[i] + 30 - 1;
    j = i;
    while(j<days.size()  && days[j]<=passday){
        j++;
    }
    int cost30 = costs[2] + solveMemo(days,costs,j,dp);

  dp[i] =  min(cost1 , min(cost7,cost30));
  return dp[i];
    
}
//TABULATION
int solveTab(vector<int>& days,vector<int>& costs){
     vector<int>dp(days.size()+1,0);
   dp[days.size()] = 0;
   for(int i=days.size()-1;i>=0;i--){

    int cost1 = costs[0] + dp[i+1];

    //7 days ka leke dekho
    int passday = days[i] + 7 - 1;
    int j = i;
    while(j<days.size()  && days[j]<=passday){
        j++;
    }
    int cost7 = costs[1] + dp[j];

    //30 days ka leke dekho
    passday = days[i] + 30 - 1;
    j = i;
    while(j<days.size()  && days[j]<=passday){
        j++;
    }
    int cost30 = costs[2] + dp[j];

  dp[i] =  min(cost1 , min(cost7,cost30));   
}
return dp[0];
}



    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //RECURSIVE 
       // return solveRec(days,costs,0);
        //MEMOIZATION
        vector<int>dp(days.size(),-1);
      //  return solveMemo(days,costs,0,dp);

        //Tabulation
        return solveTab(days,costs);
    }
};