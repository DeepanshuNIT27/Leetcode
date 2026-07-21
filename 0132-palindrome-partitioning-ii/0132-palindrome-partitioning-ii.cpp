class Solution {
public:

bool ispalindrom(int i, int j , string&s){

    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
//RECURSION 

int solveRec(int i, string&s){

    if(i == s.size()) return 0;

    int ans = INT_MAX;
    for(int j=i;j<s.size();j++){
        if(ispalindrom(i,j,s)){
            int val = 1 + solveRec(j+1,s);
            ans = min(ans,val);
        } 
    }
    return ans;
}

//MEMOIZATION 
int solveMemo(int i, string&s,vector<int>&dp){

    if(i == s.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans = INT_MAX;
    for(int j=i;j<s.size();j++){
        if(ispalindrom(i,j,s)){
            int val = 1 + solveMemo(j+1,s,dp);
            ans = min(ans,val);
        } 
    }
    return dp[i] = ans;
}
    int minCut(string s) {
        int n = s.size();
        //RECURSION 
       // return solveRec(0,s) - 1;

       //MEMOIZATION 
       vector<int>dp(n+1,-1);
       return solveMemo(0,s,dp)-1 ;
    }
};