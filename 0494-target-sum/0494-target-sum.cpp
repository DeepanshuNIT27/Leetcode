class Solution {
public:

int solveRec(int i , int sum , int &target , vector<int>& nums){

    if(i>=nums.size()) {
        if(sum == target) return 1;
        return 0;
    }

    int add = solveRec(i+1, sum+nums[i], target , nums);
    int sub = solveRec(i+1,sum - nums[i] , target, nums);

    return add + sub ;
}
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        //RECURSION 
        return solveRec(0,0,target,nums);

        
    }
};