class Solution {
public:
//RECURSIVE SOLN BINARY EXPONENTIATION

double solve(double x , long long N){
 
  if(N == 0) return 1;

  double half = solve(x,N/2);

  if(N%2 == 0) {
    return half*half;
  }
  else {
   return  half*half*x;
  }

}
    double myPow(double x, int n) {
        
        long long N = n;
        if(N<0){
           N = -N;
           x = 1/x;
        }
        double ans = solve(x,N);
        return ans;
    }
};