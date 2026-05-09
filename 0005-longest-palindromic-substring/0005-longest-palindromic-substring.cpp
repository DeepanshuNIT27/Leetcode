class Solution {
public:
//DP SOLUTION 
    string longestPalindrome(string s) {
        int n = s.size();
     vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
      int start = 0;
      int length = 1;
       for(int i=n-1;i>=0;i--){
        for(int j =i;j<n;j++){
            // 1 length 
            if(i==j){
                dp[i][j] = true;
            }

            //2 
          else  if(j-i==1 && s[i]==s[j]){
                dp[i][j] = true;
            }

            //>=3 length 
            else if(s[i]==s[j] && dp[i+1][j-1]){
                dp[i][j] = true;
            }

            //update 
            if(dp[i][j] && (j-i+1)>length){
                length = j-i+1;
                start = i;
            }
        }
       }
       return s.substr(start,length);
    }
};