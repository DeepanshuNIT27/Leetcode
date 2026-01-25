class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>a,b;
        for(auto&it:nums) {
           if(it>=0) a.push_back(it);
        }
        b = a;
        if(a.size()==0) return nums;
        int d = k%a.size();
        int m = b.size();
        for(int i=a.size()-1;i>=0;i--){
          if(d<=i) b[i-d] = a[i];
          else {
            b[m-d+i] = a[i];
          }
        }
        int j = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){ nums[i] = b[j];
            j++;
        }
        }
        return nums;
    }
};