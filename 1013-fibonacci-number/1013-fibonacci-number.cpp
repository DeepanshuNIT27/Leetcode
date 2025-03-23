class Solution {
public:
  int solvebyRecursion(int n){
    if(n==0 || n==1){
        return n;
    }
    int ans = solvebyRecursion(n-1) + solvebyRecursion(n-2);
    return ans;
 }
    int fib(int n) {
    return solvebyRecursion(n);
    }
};