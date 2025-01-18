class Solution {
public:
void printpermutation(vector<int>& nums, vector<vector<int>>&v, int i){
 if( i>= nums.size()){
    v.push_back(nums);
 }
 for(int j= i ;j< nums.size();j++){

    swap(nums[i] ,nums[j]);
    printpermutation(nums,v,i+1);
    swap(nums[i] ,nums[j]);
 }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>v;
       printpermutation(nums,v,0);
       return v;


    }
};