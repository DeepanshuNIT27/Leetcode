class Solution {
public:
  void solve (vector<vector<int>>&ans, vector<int>&curr,vector<int>& candidates, int target , int index){
    //base case
    if(index>=candidates.size() || target<0){
        return ;
    }
    if(target == 0){
        ans.push_back(curr);
        return;
    }
    //ek case hm krenge
    //include kro.
    curr.push_back(candidates[index]);
    solve(ans,curr,candidates,target-candidates[index],index);
    curr.pop_back();
    //exclude kro
    solve(ans,curr,candidates,target,index+1);
  }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(ans,curr,candidates,target,0);
        return ans;
    }
};