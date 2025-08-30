class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int mini = INT_MAX;
        char ch ;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second < mini){
                mini = it->second;
                ch = it->first;
            }
        }
        return ch -'0';
    }
};