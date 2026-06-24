class Solution {
public:

void solveRec(int i , int &sum ,vector<int>& candidates, int target,  vector<int>&temp,vector<vector<int>>&ans){

    if( i== candidates.size()) {
        if(sum == target) {
            ans.push_back(temp);
        }
        return ;
    }

    if(sum > target) return ;

    //include
    temp.push_back(candidates[i]);
    sum += candidates[i];
    solveRec(i,sum,candidates,target,temp,ans);
    temp.pop_back();
    sum -= candidates[i];

    // exclude 
    solveRec(i+1,sum,candidates,target,temp,ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        int sum = 0;

        solveRec(0,sum,candidates,target,temp,ans);
        return ans ;
    }
};