class Solution {
public:

double slidingwindow(vector<int>nums,int &k){
    int i=0 ; int j = k-1;
    int sum =0;
    for(int p=i ;p<=j ;p++){
        sum = sum+nums[p];
        
    }
      int maxsum = sum;
    j++;
    while(j<nums.size()){
        sum = sum-nums[i];
        sum = sum+nums[j];
        maxsum= max(maxsum,sum);
         i++;j++;
    }
    double s = maxsum/(double)k;
    return s;

}
    double findMaxAverage(vector<int>& nums, int k) {
      double t =slidingwindow(nums,k);
      return t;
        
    }
};