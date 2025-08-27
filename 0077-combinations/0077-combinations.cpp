class Solution {
public:
void solve(vector<vector<int>>&ans, vector<int>&curr, int start , int n, int k){
    //base case
  if(k==0){
    ans.push_back(curr);
  }
    //1 case hm dekhenge
    for(int i=start;i<=n;i++){
        curr.push_back(i);
        solve(ans,curr,i+1,n,k-1);
        curr.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(ans,curr,1,n,k);
        return ans;
        
    }
};