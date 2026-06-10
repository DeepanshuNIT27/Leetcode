class Solution {
public:
//O(N) SOLN 
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        unordered_map<char,bool>vis;
        
        int n = s.size();
        int j = 0;

        while(j<n){

            if(mp.find(s[j]) == mp.end()){

                if(vis[t[j]]) return false;
                mp[s[j]] = t[j];
                vis[t[j]] = true;
            }

            else{
                if(mp[s[j]]!= t[j]) return false;
            }
            j++;
        }
        return true;
    }
};