class Solution {
public:
//BACKTRACKING SOLN COMPLEXITY O(2^N*N).
//BRUTE FORCE SOLUTION 

void solve(int i , int n ,vector<int>& nums, vector<int>&temp ,vector<vector<int>>&ans ){
    
    if(i == n){
        ans.push_back(temp);
        return ;
    }
    //include
    temp.push_back(nums[i]);
    solve(i+1,n,nums,temp,ans);
    temp.pop_back();

    //exclude
    solve(i+1,n,nums,temp,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int index = 0;
        int n = nums.size();

        solve(index,n,nums,temp,ans);
        return ans;
    }
};