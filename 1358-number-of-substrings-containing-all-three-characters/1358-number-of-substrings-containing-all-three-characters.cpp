class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int n = s.size();
        int ans = 0;

        while(j<n){

            mp[s[j]]++;

            while( i<j && mp.size()==3){
                ans += n - j;
                if(mp[s[i]]==1) mp.erase(s[i]);
                else mp[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};