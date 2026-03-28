class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int>map(256,-1);
        int last = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(map[s[i]]>=last){
            ans = max(ans,i-last);
            last = map[s[i]] + 1;
            map[s[i]] = i;
            }
            else{
                map[s[i]] = i;
            }
        }
        return  ans = max(ans, n - last);
    }
};