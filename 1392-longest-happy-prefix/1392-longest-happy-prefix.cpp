class Solution {
public:

vector<int>kmp(string s){

    vector<int>lps(s.size(),0);

    for(int i=1;i<s.size();i++){

        int prev_index = lps[i-1];

        while(prev_index >0 && s[i] != s[prev_index]){
            prev_index = lps[prev_index - 1];
        }

        lps[i] = prev_index + (s[i] == s[prev_index] ? 1 : 0);
    }
    return lps;
}
    string longestPrefix(string s) {
        
        vector<int>ans = kmp(s);
        int n = s.size();
        return s.substr(0,ans[n-1]);
        
    }
};