class Solution {
public:
int getPivotIndex(vector<int>&nums){
    int s =0;
    int n = nums.size();
    int e = n-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(s==e){
            return s;
        }
        if( mid+1<=n && nums[mid]>nums[mid+1]){
            return mid;
        }
        if (mid-1>=0 && nums[mid] < nums[mid - 1]) {
                return mid - 1;
            }
        if(nums[mid]<nums[s]){
            e = mid-1;
        }
        else{
            s= mid+1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int binarySearch(int s ,int e ,int target ,vector<int>&nums){
int mid = s+(e-s)/2;
while(s<=e){
if(nums[mid]==target){
    return mid;
}
 else if( nums[mid]>target){
    e = mid-1;

}
 else if (nums[mid]<target){
    s=mid+1;
}
mid = s+(e-s)/2;

}
return -1;


}
    int search(vector<int>&nums, int target) {
        int pivotIndex= getPivotIndex(nums);
        int n = nums.size();
        

        if(target>=nums[0]&& target<=nums[pivotIndex]){
           int ans1 = binarySearch(0,pivotIndex,target,nums);
            return ans1;
        }
        else{
         int ans2 =binarySearch(pivotIndex+1,n-1,target,nums);
            return ans2;
        }
        return -1;
    }
};