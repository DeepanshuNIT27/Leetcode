class Solution {
public:
// METHOD-1 COMPLEXITY O(1) FOR BOTH
    int minBitFlips(int start, int goal) {

        int cnt = 0;
        for (int i = 0; i < 32; i++) {

            bool ans1 = (((start >> i) & 1) != 0);
            bool ans2 = (((goal >> i) & 1) != 0);

            if ((ans1 && !ans2) || (!ans1 && ans2))
                cnt++;
        }
        return cnt;
    }
};
