class Solution {
public:
//MEMOIZATION 0-9 DIGIT KE LIYE MASK USE KRENGE NORMAL MAP WAGERA FAIL KR JAYEGA YHA PE OR MASK ME HM COMBINATION STORE KR RHA 2^N SIZE HOGA.
int dp[10][2][2][1024];

int solve(string&num , int n, int tight , int is_start, int mask){

    if(n == 0) return 1;
    if(dp[n][tight][is_start][mask]!=-1) return dp[n][tight][is_start][mask];

    int pos =  num.length() - n;
    int ub  = tight ? (num[pos]-'0'): 9;
    
    int ans = 0;
    
    for(int i=0;i<=ub;i++){
       if(is_start == 0 && i==0){
         ans+= solve(num,n-1,0,0,mask);
       }
       else if((mask & (1<<i)) == 0){

        ans += solve(num,n-1,(tight&&(i == ub)),1, mask|(1<<i));
       }
    }
    return dp[n][tight][is_start][mask] = ans;
}
    int countNumbersWithUniqueDigits(int n){
        if(n == 0) return 1;
       
        string num = "";
        for(int i=0;i<n;i++){
            num += '9';
        }
        memset(dp,-1,sizeof(dp));
        int ans = solve(num,n,1,0,0);
        return ans;
    }
};