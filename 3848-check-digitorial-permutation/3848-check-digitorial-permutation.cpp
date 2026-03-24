class Solution {
public:
int  fact(int n, vector<int>&dp ){
    if(n==1 || n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    int ans = n * fact(n-1,dp);

    dp[n] =  ans;
    return dp[n];
}
    bool isDigitorialPermutation(int n) {
      vector<int>dp(10,-1);
      dp[0]= 1;
      dp[1] = 1;
      int k  = fact(9,dp);
      unordered_map<int,int>first;
      int sum = 0;
      while(n){
        int num = n%10;
        sum += dp[num];
        first[num]++;
        n = n/10;
      }

      unordered_map<int,int>second;
      while(sum){
        int num = sum%10;
        second[num]++;
        sum = sum/10;
      }

      if(first.size()!=second.size()) return false;
      for(auto it=second.begin();it!=second.end();it++){
        if(first[it->first]!=it->second) return false;
      }
      return true;
    }
};