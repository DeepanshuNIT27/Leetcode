class Solution {
public:
    long long coloredCells(int n) {
        long long sum  = 0L;
        for(int i=1;i<=n;i++){
            if(i==1){
                sum += 1;
            }
            else{
                sum += (4*(i-1));
            }
        }
        return sum;
    }
};