class Solution {
public:
//O(N*2^N) COMPLEXITY.
void solveRec(int i , int sum ,vector<int>& candidates, int target, vector<int>&temp , vector<vector<int>>&ans){

    if(sum == target){
        ans.push_back(temp);
        return;
    }

    for(int j= i;j<candidates.size();j++){

        if(j > i && candidates[j] == candidates[j-1]){
               continue;
        }// IT WILL HANDLE THE DUBLICATE PART .
        if(candidates[j] + sum > target) break;
        temp.push_back(candidates[j]);
        solveRec(j+1,sum+candidates[j],candidates,target,temp,ans);
        temp.pop_back();

    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     sort(candidates.begin(),candidates.end());
     vector<vector<int>>ans;
     vector<int>temp;

     solveRec(0,0,candidates,target,temp,ans);
     return ans;   
    }
};