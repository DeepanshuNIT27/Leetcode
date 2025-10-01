class Solution {
public:
 int maxSumHelper(vector<int>&nums , int start , int end){
    if(start == end) return nums[start];
    int MaxLeftBoarderSum = INT_MIN;
    int MAXRightBoarderSum = INT_MIN;
     int mid  = start +(end-start)/2;
    int maxLeftSum = maxSumHelper(nums,start,mid);
    int maxRightSum = maxSumHelper(nums,mid+1,end);

    //cross sum
    int leftBoarderSum = 0 , rightBoarderSum = 0;
    for(int i=mid;i>=start;i--){
        leftBoarderSum += nums[i];
        if(leftBoarderSum>MaxLeftBoarderSum) MaxLeftBoarderSum = leftBoarderSum;
    }
    for(int i=mid+1;i<=end;i++){
       rightBoarderSum += nums[i];
        if(rightBoarderSum>MAXRightBoarderSum) MAXRightBoarderSum = rightBoarderSum;
    }
    int crossBoarderSum =MaxLeftBoarderSum  + MAXRightBoarderSum;
    return max(crossBoarderSum,max( maxLeftSum,maxRightSum));
 }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        return maxSumHelper(nums,start,end);
    }
};