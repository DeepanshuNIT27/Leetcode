class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if((n&(n-1))==0){
         int d = log2(n);
         if(d&1) return false;
         else return true;
        }
        return false;
    }
    };