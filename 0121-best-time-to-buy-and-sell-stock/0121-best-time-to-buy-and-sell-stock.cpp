class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
       int mini = prices[0];
       int ans = 0;
       int n = prices.size();

       for(int i=1;i<n;i++){
          
          mini = min(mini,prices[i]);

          if(prices[i]>mini){
             ans = max(ans, prices[i] - mini);
          }
       }
       return ans;
    }
};