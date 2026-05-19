class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        
        int n = s.size();
        for(int i=1;i<n;i++){
            int d = abs((s[i]-'0') - (s[i-1]-'0'));
            if(d>2) return false;
            
        }
        return true;
    }
};