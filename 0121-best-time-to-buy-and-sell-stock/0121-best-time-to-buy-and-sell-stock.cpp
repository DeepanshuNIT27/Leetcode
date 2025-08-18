class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int ans = INT_MIN;
        for(int i=0;i<prices.size();i++){
            int curr = prices[i];
            mini = min(curr,mini);
            ans = max((curr-mini),ans);
        }
        return ans;
    }
};