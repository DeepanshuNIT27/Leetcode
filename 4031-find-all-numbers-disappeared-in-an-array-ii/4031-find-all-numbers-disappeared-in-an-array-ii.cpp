class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<vector<int>>v;

        sort(nums.begin(),nums.end());

        int s = lower ;

        for(int i=0;i<n;i++){

            if(nums[i]>upper) break;
            if(nums[i] < lower) continue;

            if(nums[i] >  s){
                v.push_back({s,nums[i]-1});
            }
            
            if (nums[i] >= s) {
                s = nums[i] + 1;
            }

        }
        if(s <= upper){

            v.push_back({s,upper});
        }
        return v;
    }
};