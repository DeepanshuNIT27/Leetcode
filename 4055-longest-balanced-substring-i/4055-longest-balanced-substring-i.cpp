class Solution {
public:
void solve(unordered_map<char,int>&mp,int &ans){
    bool flag = true;
    auto it = mp.begin();
    int z = it->second;
    for(auto&it1:mp){
     if(it1.second!=z){
        flag = false;
        break;
     }
    }
    if(flag==true) ans = max(ans, (int)( mp.size()*z));
}
    int longestBalanced(string s) {
        unordered_map<char,int>mp;
        int ans = INT_MIN;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                solve(mp,ans);
            }
            mp.clear();
        }
        return ans;
    }
};