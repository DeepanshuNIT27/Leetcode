class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
//open bracket hai
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            //close bracket ho
            else{
                if(ch==')' && !st.empty() && st.top()=='('){
                    st.pop();
                }
                else if(ch=='}' && !st.empty() && st.top()=='{'){
                    st.pop();
                }
               else if(ch==']' && !st.empty() && st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
        
    }
};