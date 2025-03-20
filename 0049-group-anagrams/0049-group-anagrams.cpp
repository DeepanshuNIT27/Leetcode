class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            auto original = strs[i];
            auto copy = strs[i];
            sort(copy.begin(),copy.end());
            mp[copy].push_back(original);
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
       return ans; 
    }
};