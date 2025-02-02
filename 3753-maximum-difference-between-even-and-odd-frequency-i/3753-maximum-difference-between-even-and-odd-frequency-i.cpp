class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>map;
        for(int i=0 ;i<s.size();i++){
            map[s[i]]++;
        }
        int a = INT_MAX;
        int b = INT_MIN;
        for( auto it= map.begin();it!=map.end();it++){
            if(it->second%2!=0){
                b = max(b ,it->second);
            }
            else{
                a = min(a,it->second);
            }
        }
        return b-a;
    }
};