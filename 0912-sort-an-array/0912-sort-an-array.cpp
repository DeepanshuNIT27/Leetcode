class Solution {
public:
//QUICK SORT .
// BEST ANG AVG IS O(N*LOG*N).
// WORST CASE IS O(N^2) WHEN IT IS ALREADY SORTED.

int partition(vector<int>& nums, int low , int high){

    int pivot = nums[low];
    int i = low;
    int j = high;

    while(i<j){

        while( i<=high-1&& nums[i]<=pivot ){
            i++;
        }

     while( j>=low+1 && nums[j] > pivot ){
        j--;
     }

     
if(i<j ) swap(nums[i],nums[j]);

    }
    swap(nums[low],nums[j]);
    return j;
}

void qs(vector<int>& nums, int low , int high){

     if (low >= high) return;

    int pIndex = partition(nums,low,high);

    qs(nums,low,pIndex-1);
    qs(nums,pIndex+1,high);

}
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size()-1;
        qs(nums,0,n);
        return nums;
    }
};