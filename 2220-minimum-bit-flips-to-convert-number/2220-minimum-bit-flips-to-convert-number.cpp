class Solution {
public:
// COMMON SOLN BY OBSERVATION 
    int minBitFlips(int start, int goal) {
        
        int d = start^goal;
        int cnt = __builtin_popcount(d);
        return cnt;
    }
};