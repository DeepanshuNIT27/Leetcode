class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int>mp;
        vector<int>v;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            v.push_back(it->second);
        }
        sort(v.begin(),v.end());
        if(v.size()<=k) return 0;
        else{
            int n = v.size();
            int count = 0;
            for(int i=0;i<v.size();i++){
                if(n<=k) break;
                else{
                    count += v[i];
                    n--;
                }
            }
            return count;
        }
        return 0;
    }
};