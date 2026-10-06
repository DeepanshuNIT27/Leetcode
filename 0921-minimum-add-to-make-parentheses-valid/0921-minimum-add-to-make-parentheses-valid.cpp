class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char>st;
        int ans = 0;
        for(auto&it:s){
            if(it == '(') st.push('(');
            else {
                if(!st.empty()) st.pop();
                else ans++;
            }
        }
        return ans + st.size();
    }
};