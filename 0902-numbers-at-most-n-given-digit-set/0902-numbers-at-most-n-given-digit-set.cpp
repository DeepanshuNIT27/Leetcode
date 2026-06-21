//CONSTANT COMPLEXITY.
// DO NOT FORGET ABOUT LESS DIGIT NUMBERS.
class Solution {
public:
   int dp[12][2][2];

    int solve(string&num , int n , int tight ,int is_start,   unordered_map<char,bool>&mp ){

        if(n == 0) return is_start;
        if(dp[n][tight][is_start]!= -1) return dp[n][tight][is_start];

        int pos = num.length() - n;

        int ub = tight ? (num[pos]-'0') : 9;
    // abhi number bnna start ni hua hai 0 bhar skte ho start me 
       int ans = 0;
       if(is_start == 0){
         ans += solve(num,n-1,0,0,mp);
       }

       for(int i=0;i<=ub;i++){

          char ch = i + '0';
          if(mp.find(ch)!=mp.end()){
             
             ans += solve(num,n-1,(tight&&(num[pos]-'0' == i)),1,mp);
          }
       }
       return dp[n][tight][is_start]= ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        string  num = to_string(n);
        unordered_map<char,bool>mp;
        for(auto&it:digits){
            char ch = it[0];
            mp[ch] = true;
        }
        memset(dp,-1,sizeof(dp));
        int ans = solve(num,num.length(),1,0,mp);
        return ans;
    }
};