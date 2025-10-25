class Solution {
public:
    int totalMoney(int n) {
        long long ans = 0LL;
        int count = 0;
        while(n>0){
         if(n<7){
            ans += n*(n+1)/2 + count*n;
             break;
         }
         else{
            ans += 28 + count*7;
            count++;
             n -= 7;

         }
        }
        return ans;
    }
};