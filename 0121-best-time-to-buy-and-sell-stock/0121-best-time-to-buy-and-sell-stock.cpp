class Solution {
public: 
 void solve(vector<int>& prices,int &mini , int & ans , int index){
      
      //base case 
      if(index>=prices.size()){
        return;
      }
        int curr = prices[index];
        mini = min(curr,mini);
        ans = max((curr-mini),ans);
        solve(prices,mini,ans,index+1);
 }
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int ans = INT_MIN;
        solve(prices,mini,ans,0);
return ans;
    }
};
 