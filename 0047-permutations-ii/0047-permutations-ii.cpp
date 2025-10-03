class Solution {
public:
//OPTIMIZED WAY TO HANDLE DUBLICATES AT RUNTIME
void PermtationTwo( vector<vector<int>>&ans,vector<int>& nums,int start){
    //BASE CASE
    if(start>=nums.size()){
        ans.push_back(nums);
        return ;
    }
    unordered_map<int,bool>visited;
    for(int i=start;i<nums.size();i++){
        if(visited.find(nums[i])!= visited.end()) continue;
        visited[nums[i]] = true;
        swap(nums[start],nums[i]);
        PermtationTwo(ans,nums,start+1);
        swap(nums[start],nums[i]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
      PermtationTwo(ans,nums,0);
        return ans;
    }
};