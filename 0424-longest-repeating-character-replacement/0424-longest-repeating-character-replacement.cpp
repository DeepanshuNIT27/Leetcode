class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans = 0;
        int maxi = 0;
        unordered_map<char,int>mp;
        while(j<n){
          
         mp[s[j]]++;
         maxi = max(maxi,mp[s[j]]);

         while(i<j && ((j-i+1)-maxi)>k){
            mp[s[i]]--;
            maxi = 0;
            for(auto it : mp) maxi = max(maxi,it.second);
            i++;
         }

         ans = max(ans,j-i+1);
         j++;
        }
        return ans;
    }
};