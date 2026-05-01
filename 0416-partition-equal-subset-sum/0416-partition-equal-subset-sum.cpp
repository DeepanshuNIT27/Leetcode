class Solution {
public:
//Recursion 
bool solveRec(int i , int sum ,vector<int>& nums){
    //Base case
    if(i>=nums.size()){
        if(sum == 0) return true;
        else return false;
    }

    bool inc = solveRec(i+1,sum-nums[i],nums);
    bool exc = solveRec(i+1,sum,nums);

    return inc || exc ;
}
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;

        return solveRec(0,sum/2,nums);
    }
};