 class Solution {
public:
int firstoccurance(vector<int>&nums,int target){
  int s = 0;
          int n = nums.size();
    int e = n - 1;
    int mid;
    int ans1 =-1;
    mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans1= mid;
            e = mid - 1;
        }
        if (nums[mid] < target)
        {
            s = mid + 1;
        }
        if (nums[mid] > target)
        {
            e = mid - 1;
        }
        mid = s+(e-s)/2;

        
    }
    return ans1;
}
int lastoccurance(vector<int>&nums,int target){
  int s = 0;
          int n = nums.size();
    int e = n - 1;
    int mid;
    int ans2 =-1;
    mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans2= mid;
            s = mid + 1;
        }
        if (nums[mid] < target)
        {
            s = mid + 1;
        }
        if (nums[mid] > target)
        {
            e = mid - 1;
        }
        mid = s+(e-s)/2;

        
    }
    return ans2;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>arr(2);
      int a=  firstoccurance(nums, target);
     int b =   lastoccurance(nums, target);

arr[0]=a;
arr[1]=b;

return arr;
    

}
 };      

