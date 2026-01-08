class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int>v(256,-1);
        int temp = 0;
        int ans = INT_MIN;
        for(int i=0;i<s.size();i++){
            if(v[(int)s[i]]!=-1){
            ans = max(ans,i-temp);
            int j=temp;
            for(;j<=v[(int)s[i]];j++){
                v[(int)s[j]] = -1;
            }
            temp = j;
            v[(int)s[i]] = i;
            }
            else{
                v[(int)s[i]] = i;
            }
        }
        ans  = max(ans,n-temp);
        if(ans==INT_MIN) return s.size();
        return  ans;
    }
};