class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string ans = "";
        int n = s.size();
        int count = 0;
        int start = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '(' )count++;
            else count--;

            if(count == 0) {
                ans+= s.substr(start+1,i-start-1);
                start = i+1;
            }
        }
        return ans;
    }
};