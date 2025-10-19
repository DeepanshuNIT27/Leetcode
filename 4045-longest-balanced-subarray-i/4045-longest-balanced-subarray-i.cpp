class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_map<int,int>mp;
        int counte = 0;
        int counto = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                
                if(nums[j]%2==0 && mp.find(nums[j])==mp.end()) {
                    mp[nums[j]]++;
                    counte++;
                }
                if(nums[j]%2!=0 && mp.find(nums[j])==mp.end()){
                    mp[nums[j]]++;
                    counto++;
                }
                if(counte == counto){
                    ans = max(ans,j-i+1);
                }
                
            }
            mp.clear();
            counte = 0; 
            counto = 0;
        }
        return ans;
    }
};