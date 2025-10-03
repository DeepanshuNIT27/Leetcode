class Solution {
public:
void solve(vector<int>& candidates,vector<vector<int>>&ans,  vector<int>&temp, int target , int index){
    //BASE CASE
    if(index >= candidates.size() || target<0) return ;
    if(target == 0){
        ans.push_back(temp);
        return ;
    }
    // 1 CASE HM SMBHALENGE
    //include
    temp.push_back(candidates[index]);
    solve(candidates,ans,temp,target-candidates[index],index);
    temp.pop_back();
    //exclude
    solve(candidates,ans,temp,target,index+1);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int index = 0;
        solve(candidates,ans,temp,target,index);
return ans;
    }
};