class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n = numBottles;
        int ans = numBottles;
        while(n>=numExchange){
            ans += n/numExchange;
            n = n/numExchange+ n%numExchange;
        }
       return ans; 
    }
};