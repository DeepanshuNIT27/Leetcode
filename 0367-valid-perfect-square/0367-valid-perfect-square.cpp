class Solution {
public:
    bool isPerfectSquare(int num) {
        int s=0;
        int e = num;
        long long int mid = s+(e-s)/2;
        while(s<=e){
            long long int product = (long long int) mid*mid;
            if(product==num){
                return true;
            }
            if(product>num){
                e = mid-1;
            }
            else{
                s =mid+1;
            }
            mid = s+(e-s)/2;
        }

        return false;
    }
};