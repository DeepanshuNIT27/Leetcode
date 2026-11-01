class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
         int temp = 1e9;
        for(int i=0;i<n-1;i+=2){
            string p = "";
             p += to_string(nums[i]);
             p += to_string(nums[i+1]);
             int ans = stoi(p);
             temp = min(temp,ans);
        }
        return temp;
    }
};