class Solution {
public:
 void merge(vector<int>&nums, int start , int mid , int end){
    int length = end - start + 1;
    int gap = length/2 + length%2;
    while(gap>0){
        int i = start , j = i + gap;
        while(j<=end){
        if(nums[i]>nums[j]){
            swap(nums[i],nums[j]);
        }
        i++ ,j++;
        }
        gap = gap<=1 ? 0 : gap/2+gap%2;
    }
 }
void mergesort(vector<int>&nums , int start , int end){
    if(start>=end) return;
    int mid = start +(end-start)/2;
    mergesort(nums,start,mid);
    mergesort(nums,mid+1,end);
    merge(nums,start,mid,end);
}
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        mergesort(nums,start,end);
        return nums;
    }
};