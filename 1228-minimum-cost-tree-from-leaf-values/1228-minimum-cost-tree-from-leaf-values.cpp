class Solution {
public:
//recursive soln
int solveUsingRecu(vector<int>&arr,map<pair<int,int>,int>&maxi , int s ,int e){
    //base case 
    if(s>=e){
        return 0;
    }
    int ans = INT_MAX;
    for(int i=s;i<e;i++){
        int leftRangeKaMax = maxi[{s,i}];
        int rightRangeKaMax = maxi[{i+1,e}];
        int nonLeafvalue = leftRangeKaMax * rightRangeKaMax;
        ans = min(ans,nonLeafvalue+solveUsingRecu(arr,maxi,s,i)+solveUsingRecu(arr,maxi,i+1,e));

    }
    return ans;
}
//MEMO
int solveUsingMemo(vector<int>&arr,map<pair<int,int>,int>&maxi , int s ,int e,vector<vector<int>>&dp){
    //base case 
    if(s>=e){
        return 0;
    }
    if(dp[s][e]!=-1) return dp[s][e];
    int ans = INT_MAX;
    for(int i=s;i<e;i++){
        int leftRangeKaMax = maxi[{s,i}];
        int rightRangeKaMax = maxi[{i+1,e}];
        int nonLeafvalue = leftRangeKaMax * rightRangeKaMax;
        ans = min(ans,nonLeafvalue+solveUsingMemo(arr,maxi,s,i,dp)+solveUsingMemo(arr,maxi,i+1,e,dp));
    }
    dp[s][e] = ans;
    return dp[s][e];
}
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
            if(i == j){
                maxi[{i,j}] = arr[i];
            }
            else{
                maxi[{i,j}] = max(maxi[{i,j-1}],arr[j]);
            }
            }
        }
        int s = 0;
        int e = arr.size()-1;
        //recursive soln
        //return solveUsingRecu(arr,maxi,s,e);
      
      //2-d dp 
      //memo
      vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
      return solveUsingMemo(arr,maxi,s,e,dp);
    }
};