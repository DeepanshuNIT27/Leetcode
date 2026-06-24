class Solution {
public:
// FOR THIS KIND OF PROBLEM LOOP METHOD IS EASY TO IMPLEMENT .
//HERE WE NEED TO REMOVE DUBLICATE AND ALSO REMEMBER HERE EVEY STATE IS A SUBSET STATE .
// COMPLEXITY (2^N * N).
void solveRec(int i , vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans){

    ans.push_back(temp);

    for(int j=i;j<nums.size();j++){
        if(j>i && nums[j] == nums[j-1]) continue;

        temp.push_back(nums[j]);
        solveRec(j+1,nums,temp,ans);
        temp.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
          vector<vector<int>>ans;
          vector<int>temp;

          solveRec(0,nums,temp,ans);
          return ans;
    }
};