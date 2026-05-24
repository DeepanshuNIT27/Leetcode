class Solution {
public:
    int passwordStrength(string password) {
        unordered_map<char,int>mp;
        for(auto&it:password) mp[it]++;

        string s = "";
        for(auto&it:mp){
            s+= it.first;
        }
        int ans = 0;
        for(int i=0;i<s.size();i++){
           char ch = s[i];

           if(ch>='a' && ch<='z') ans += 1;
           else if(ch>='A' && ch<='Z') ans+= 2;
           else if(ch>='0' && ch<='9') ans += 3;
           else ans+= 5;
        }
        return ans ;
    }
};