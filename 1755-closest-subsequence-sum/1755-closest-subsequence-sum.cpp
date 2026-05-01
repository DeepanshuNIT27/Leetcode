class Solution {
public:

vector<int>getAllSum(vector<int>&nums , int l , int r){

    vector<int>res;
    int n = r- l + 1;

    for(int mask = 0; mask < (1<<n) ; mask++){

        int sum = 0;

        for(int j=0;j<n;j++){
            if(mask&(1<<j)){
                sum += nums[l+j];
            }
        }
        res.push_back(sum);
    }
    return res;
}
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n/2;

        vector<int>left = getAllSum(nums,0,mid-1);
        vector<int>right = getAllSum(nums,mid,n-1);

        sort(right.begin(),right.end());

        int ans = INT_MAX;

        for(auto x : left){
            int target = goal - x;

            auto it = lower_bound(right.begin(),right.end(),target);

            if(it!=right.end()){
                ans = min(ans,abs(goal - (x + *it)));
            }

            if(it!=right.begin()){
                it--;
                ans = min(ans,abs(goal - (x+*it)));
            }


        }
        return ans;
        
    }
};