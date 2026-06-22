class Solution {
public:
 long long dp[20][2][10][2];

 long long solve(string num , long long n ,long long tight , long long prev, long long is_start, long long k){

    if(n == 0) return is_start;
    if(dp[n][tight][prev][is_start]!=-1) return dp[n][tight][prev][is_start];

    long long pos = num.size() - n;

    long long ub = tight ? num[pos]-'0' : 9;
    long long ans = 0LL;

    for(int i=0;i<=ub;i++){

       if(is_start ==0 && i==0 ){
        ans += solve(num,n-1,(tight&&(i == ub)),i,0,k);
       }
       else if(is_start == 0 && i>0 ){
         ans += solve(num,n-1,(tight&&(i==ub)),i,1,k);
       }
       else if(abs(i-prev)<=k){
        ans += solve(num,n-1,(tight&&(i==ub)),i,1,k);
       }
    }
    return dp[n][tight][prev][is_start] = ans;
 }
    long long goodIntegers(long long l, long long r, int k) {
        
        string left = to_string(l-1);
        string right = to_string(r);
        
        memset(dp,-1,sizeof(dp));
        long long x = solve(left,left.size(),1,0,0,k);
        memset(dp,-1,sizeof(dp));
        long long y = solve(right,right.size(),1,0,0,k);

        return  y-x;
    }
};