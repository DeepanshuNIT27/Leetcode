class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>v;
        vector<int>b;
        int count = 0;
        for(int i=0 ;i<nums.size();i++){
            if(nums[i]<pivot){
                v.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                b.push_back(nums[i]);
            }
            else{
                count++;
            }
        }
        while(count--){
            v.push_back(pivot);
        }
        for(int i=0 ;i<b.size();i++){
            v.push_back(b[i]);
        }
        return v;
    }
};