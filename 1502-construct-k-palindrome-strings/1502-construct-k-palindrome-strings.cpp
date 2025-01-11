class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>m;
        int count = 0;
        for(int i=0 ;i< s.size();i++){
            char ch = s[i];
            m[ch]++;
        }
        for (const auto& pair : m){
            if((pair.second&1)){
                count++;
            }
        }
        if(count<=k && k<=s.size()){
            return true;
        }
        else{
            return false;
        }
    }
};