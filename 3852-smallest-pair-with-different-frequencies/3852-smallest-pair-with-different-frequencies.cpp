class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        
       map<int,int>mp;
       vector<int>ans;
       for(auto&it:nums) mp[it]++;
      int search = mp[mp.begin()->first];
      for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second!=search){
          ans.push_back(mp.begin()->first);
          ans.push_back(it->first);
          break;
        }
      }
      if(ans.size()) return ans;
      ans.push_back(-1);
      ans.push_back(-1);
      return ans;
        
    }
};