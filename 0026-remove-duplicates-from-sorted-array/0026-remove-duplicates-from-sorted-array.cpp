class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>arr;
        int n = nums.size();
        // if(n==0){
        //     return 0;
        // }
        if(n==1){
            return 1;
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1] ){
               arr.push_back(nums[i]);
            }
        }
        arr.push_back(nums[n-1]);
        for(int j=0 ;j<arr.size();j++){
            nums[j]=arr[j];
        }
        
    // for(int j=0 ;j<arr.size();j++){
    //     cout<<nums[j]<<endl;
    // }
        return arr.size();
    }
};