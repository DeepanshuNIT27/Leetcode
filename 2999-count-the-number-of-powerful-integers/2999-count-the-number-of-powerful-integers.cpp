//DIGIT DP CONSTANT COMPLEXITY .
class Solution {
public:
long long dp[20][2];

long long solve(string &num ,string&s , int tight , int n ,int limit ){
    
  
    if(num.length() < s.length()) return 0LL;
    if(n == 0) return 1LL;
    if(dp[n][tight]!=-1) return dp[n][tight];

    int  pos = num.length() - n;
    int ub = tight ? num[pos] -'0' : 9;

    long long ans = 0LL;

    if(n<=s.length()){
        
            int a = s[s.length()-n] - '0';
            if(a>ub){
               return dp[n][tight] = 0LL;
        
            }
          ans += solve(num,s, tight&&(a == ub) ,n-1,limit);
    }
    else{
        for(int i=0;i<=ub && i<=limit ;i++){
            ans =ans + solve(num,s,(tight&&(i==ub)) , n-1, limit);
        }
    }
    return dp[n][tight] = ans;
}

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {

        string r = to_string(finish);
        string l = to_string(start-1);

        memset(dp,-1,sizeof(dp));
        long long a  = solve(r,s,1,r.length(),limit);
        memset(dp,-1,sizeof(dp));
        long long b = solve(l,s,1,l.length(),limit);

        return  a-b;
        
    }
};