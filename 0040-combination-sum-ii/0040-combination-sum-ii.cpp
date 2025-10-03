class Solution {
public:
void solve(vector<int>& candidates, vector<vector<int>>&ans, vector<int>&temp, int target ,int index){
    //base case
    if(target == 0){
        ans.push_back(temp);
        return ;
    }
    if(index>=candidates.size() || target<0) return;
    //include
    temp.push_back(candidates[index]);
    solve(candidates,ans,temp,target-candidates[index],index+1);
    temp.pop_back();
    //exclude
    while(index+1< candidates.size() && candidates[index]==candidates[index+1]) index++;
    solve(candidates,ans,temp,target,index+1);
    
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates,ans,temp,target,0);
        return ans;
    }
};