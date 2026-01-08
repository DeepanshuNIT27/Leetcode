class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        if(s[n-1]=='2') return s;
        int i = n-1;
        while(i>=0) {
            if(s[i]!='1') {
                string k = s.substr(0,i+1);
                return k;
            }
            i--;
            
        }
        return "";
    }
};