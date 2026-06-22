class Solution {
public:
// APPLYING KMP COMPLEXITY O(N+M) TIME AND SPACE .
vector<int>kmp(string s){
    vector<int>lps(s.size(),0);

    for(int i=1;i<s.size();i++){

        int prev_index = lps[i-1];

        while(prev_index> 0 && s[i]!=s[prev_index]){
            prev_index = lps[prev_index - 1];
        }

        lps[i] = prev_index + (s[i] == s[prev_index] ? 1 : 0);
    }
    return lps;
}
    int strStr(string haystack, string needle) {
        
        string s = needle + "#" +  haystack;
        vector<int>ans = kmp(s);
        for(int i=0;i<ans.size();i++){

            int el = ans[i];
            if(el == needle.size()){
                int idx = i;
                if(i - 2*needle.size() >=0) return i-2*needle.size();
            }
        }
        return -1;
    }
};