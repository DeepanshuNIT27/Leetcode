class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>v(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            int element = nums[i];
            for(int j=1;j<=element;j++){
                if((j |j+1)==element){
                     v[i] = j; 
                break;}
            }
        }
        return v;
    }
};