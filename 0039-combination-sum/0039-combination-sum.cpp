class Solution {
public:

void solveRec(int i , int &sum ,vector<int>& candidates, int target,  vector<int>&temp,vector<vector<int>>&ans){

    if(sum == target) {
        ans.push_back(temp);
        return ;
    }

    for(int j=i;j<candidates.size();j++){
        if(candidates[j] + sum > target) break ;

        temp.push_back(candidates[j]);
        sum += candidates[j];
        solveRec(j,sum,candidates,target,temp,ans);
        sum -= candidates[j];
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        int sum = 0;
        sort(candidates.begin(),candidates.end());
        solveRec(0,sum,candidates,target,temp,ans);
        return ans ;
    }
};