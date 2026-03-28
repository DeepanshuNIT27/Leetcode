class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<bool>visited(256,false);
        int i = 0; int j=0;
        int ans = 0;
        while(j<s.size()){
            if(visited[s[j]]== true){
                ans = max(ans , j-i);
                while( i<j &&s[i]!=s[j]){ visited[s[i]] = false; i++; }
                i++;

            }
           
           else{
            visited[s[j]] = true;
           }
            j++;
        }
        return max(ans,n-i);
    }
};