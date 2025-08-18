class Solution {
public:
void solve(vector<int>& prices,int index , int &mini , int &maxi){
    //base case
    if(index>=prices.size()){
        return ;
    }
    if(prices[index]<mini){
        mini = prices[index];
    }
    if((prices[index]-mini)>maxi){
        maxi = (prices[index]-mini);
    }
    solve(prices,index+1,mini,maxi);
}
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        solve(prices,0,mini,maxi);
        return maxi;
    }
};