class Solution {
public:
// O(N) SOLUTION AND SPACE.
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char>mp;
        unordered_map<char,bool>mp1;

        int n = s.size();
        int j = 0;

        while(j<n){

            if(s[j] == t[j]){
               
               if(mp.find(s[j]) ==mp.end()) {
                if(mp1[t[j]]) return false;
                mp[s[j]] = t[j];
                mp1[t[j]] = true;
               }
               else{
                   if(mp[s[j]] !=t[j]) return false;
               }
            }
            else{

                if(mp.find(s[j])==mp.end() && mp1[t[j]]==false){
                   mp[s[j]] = t[j];
                   mp1[t[j]] = true;
                }
                else if(mp.find(s[j])==mp.end()&& mp1[t[j]]==true) return false;

                else {
                    if(mp[s[j]]!=t[j]) return false;
                }
            }
            j++;
        }
        return true;
    }
};