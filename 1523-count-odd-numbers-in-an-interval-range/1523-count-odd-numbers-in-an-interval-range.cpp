class Solution {
public:
    int countOdds(int low, int high) {
        int x = (high+1)/2;
        int y = low / 2;
        return x-y;
    }
};