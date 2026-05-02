class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();

        vector<int>prev(n,0);
        vector<int>next(n,0);
        vector<int>ans;
        prev[0] = nums[0];
        next[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            prev[i] = max(prev[i-1] , nums[i-1]);
        }

        for(int i=n-2;i>=0;i--){
            next[i] = max(next[i+1], nums[i+1]);
        }

        for(int i=0;i<n;i++){
            if(i == 0 || i==n-1){
                ans.push_back(nums[i]) ;
                continue;
            }

            if(next[i] < nums[i]  || prev[i] <nums[i]) ans.push_back(nums[i]);
        }
        return ans;
    }

};