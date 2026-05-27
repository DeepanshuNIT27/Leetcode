class Solution {
public:
// jo element push kr rhe ho ussepahle koi bd element hoga to pop kre 
//agr k>0 hai to sare traversal ke bad v k bach jaye to pichhe se jitna hai  bacha hai use pop kro .
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n = num.size();

        int i = 0;
        while(i<n){
            if(k<=0) {
                st.push(num[i]);
                i++;
                continue;
                
            }

            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();k--;
            }

            st.push(num[i]);
            i++;
        }
        while(k>0){
            st.pop();
            k--;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int j = 0;
        for(;j<ans.size();j++){
            if(ans[j]!='0') break;
        }
        if( j== ans.size()) return "0";
        return ans.substr(j);
    }
};