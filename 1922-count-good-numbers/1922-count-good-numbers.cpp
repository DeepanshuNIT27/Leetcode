class Solution {
public:
//BY OBSERVATION 4,5 COME AND APPLY BINARY EXPONETIATION RECURSIVE MANNER 
//BECAUSEN IS 1E15.
const long long mod = 1e9+7;

long long solve(long long x , long long n){

    if(n == 0) return 1;

    long long half = solve(x,n/2);

    if(n%2 == 0) {
        return (1LL*half*half)%mod;
    }
    else {
        return (1LL*half*half*x)%mod;
    }
}
    int countGoodNumbers(long long n) {
        
        long long even = (n+1)/2;
        long long odd = n/2;

        long long ans = ((solve(5,even) % mod)*(solve(4,odd) %mod))%mod;

        return (int)ans;
    }
};