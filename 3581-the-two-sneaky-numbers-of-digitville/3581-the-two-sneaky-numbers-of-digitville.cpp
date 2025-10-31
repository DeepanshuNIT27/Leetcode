class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        vector<bool>visited(nums.size()+1,false);
        for(int i=0;i<nums.size();i++){
            if(visited[nums[i]]==true){
             ans.push_back(nums[i]);
             if(ans.size()==2) return ans;
            }
            visited[nums[i]] = true;
        }

        return ans;
    }
};