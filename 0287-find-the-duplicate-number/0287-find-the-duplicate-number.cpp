class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int p=0;
        unordered_map<int,int>mapping;
        for(int i=0;i<n;i++){
            mapping[nums[i]]++;
        }
        for(auto it =mapping.begin();it!=mapping.end();it++){
            if(it->second>=2){
            p= it->first;
            }
        }
        return p;
    }
};