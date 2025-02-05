class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        if(s1==s2) return true;
        unordered_map<char,int>map1;
         unordered_map<char,int>map2;
       for(int i=0 ;i<s1.size();i++){
        map1[s1[i]]++;
        map2[s2[i]]++;
        }
        for(int i=0 ;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                count++;
            }
            char ch = s1[i];
            char ph = s2[i];
            if(map1[ch]!=map2[ch] || map1[ph]!=map2[ph]){
                return false;
            }
        }
        bool ans = count==2 ? true: false;
        return ans;
        
    }
};