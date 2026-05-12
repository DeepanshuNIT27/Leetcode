class Solution {
public:

int goodArray(vector<int>& nums, int k ){

    int i = 0;
    int j = 0;
    int n = nums.size();
    unordered_map<int,int>mp;
    int ans = 0;

    while(j<n){
        mp[nums[j]]++;

        while(mp.size()>k){
            if(mp[nums[i]]==1) mp.erase(nums[i]);
            else mp[nums[i]]--;
            i++;
        }

        ans += j-i+1;
        j++;

    }
    return  ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return goodArray(nums,k) - goodArray(nums,k-1);

        
    }
};