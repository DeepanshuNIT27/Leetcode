class Solution {
public:

//RECURSION 
int solveRec(int i,vector<int>& stoneValue){
    if(i>=stoneValue.size()) return 0;

    int ans1 = INT_MIN;int ans2= INT_MIN; int ans3 = INT_MIN;

    ans1 = stoneValue[i] - solveRec(i+1,stoneValue);

    if(i+1<stoneValue.size()){
        ans2 = (stoneValue[i] + stoneValue[i+1]) - solveRec(i+2,stoneValue);
    }

    if(i+2<stoneValue.size()){
        ans3 = (stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]) - solveRec(i+3,stoneValue);
    }
        return max(ans1,max(ans2,ans3));
    
}

// MEMOIZATION

int solveMemo(int i,vector<int>& stoneValue, vector<int>&dp){
    if(i>=stoneValue.size()) return 0;
    if(dp[i]!=1e9) return dp[i];
    int ans1 = INT_MIN;int ans2= INT_MIN; int ans3 = INT_MIN;

    ans1 = stoneValue[i] - solveMemo(i+1,stoneValue,dp);

    if(i+1<stoneValue.size()){
        ans2 = (stoneValue[i] + stoneValue[i+1]) - solveMemo(i+2,stoneValue,dp);
    }

    if(i+2<stoneValue.size()){
        ans3 = (stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]) - solveMemo(i+3,stoneValue,dp);
    }
        return dp[i] =  max(ans1,max(ans2,ans3));
    
}

// Tabulation 

int solveTab(vector<int>& stoneValue){
    int n = stoneValue.size();
     vector<int>dp(n+1,0);

     for(int i=n-1;i>=0;i--){
     int ans1 = INT_MIN;int ans2= INT_MIN; int ans3 = INT_MIN;

    ans1 = stoneValue[i] - dp[i+1];

    if(i+1<stoneValue.size()){
        ans2 = (stoneValue[i] + stoneValue[i+1]) - dp[i+2];
    }

    if(i+2<stoneValue.size()){
        ans3 = (stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]) - dp[i+3];
    }

    dp[i] = max(ans1,max(ans2,ans3));
     }
     return dp[0];
}

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        //RECURSION 
    //   int  ans = solveRec(0,stoneValue);
    //   if(ans>0) return "Alice";
    //   else if(ans<0) return "Bob";
    //   return "Tie";


      // MEMOIZATION 
     // vector<int>dp(n+1,1e9);
    //   int ans = solveMemo(0,stoneValue,dp);
    //    if(ans>0) return "Alice";
    //    else if(ans<0) return "Bob";
    //    return "Tie";

    // Tabulation 
     int ans = solveTab(stoneValue);
       if(ans>0) return "Alice";
       else if(ans<0) return "Bob";
       return "Tie";
        
    }
};