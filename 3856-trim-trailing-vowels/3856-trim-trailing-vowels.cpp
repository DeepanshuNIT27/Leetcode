class Solution {
public:
    string trimTrailingVowels(string s) {
        set<char>st = {'a','e','i','o','u'};
        string ans = "";
        for(int i=s.size()-1;i>=0;i--){
            if(st.find(s[i])!=st.end()) continue;
            else {
                ans = s.substr(0,i+1);
                break;
            }
        }
return ans;
    }
};