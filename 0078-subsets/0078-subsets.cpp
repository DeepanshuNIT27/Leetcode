class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
     vector<vector<int>>ans;

     int num = nums.size();
     int n = (1<<num);

     for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<num;j++){
            if((i>>j)&1 !=0) {
                temp.push_back(nums[num-j-1]);
            }
        }
        ans.push_back(temp);
     }

return ans ;
    }
};