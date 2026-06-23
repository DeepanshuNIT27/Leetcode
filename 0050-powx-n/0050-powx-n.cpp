//ITERATIVE SOLUTION 
//Binary Exponentiation
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        
        if(N<0){
            N = -N;
            x = 1/x;
        }
      

      double ans = 1.0;
        while(N){
             
             if(N&1){
                ans *= x;
             }

             x = x*x;
             N = N>>1;
        }
        return ans ;
    }
};