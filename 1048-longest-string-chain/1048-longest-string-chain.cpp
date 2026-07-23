class Solution {
public:

// QUE KO DECODE KRO LIS PATTERN DIKHEGA TUMHE . COMPLEXITY O(N^2).
bool match(string&prev , string&s){

    if (prev.size() + 1 != s.size()) return false;

    int i=0; int j=0;
    while(i<prev.size() && j<s.size()){
         
         if(prev[i] !=s[j]) {
            j++;
         }
        else{
            i++;j++;
        }
    }
    return (i == prev.size());
}

struct mycom
{
   bool operator()(const string&a ,const string&b) const {
        return a.size() < b.size();
    }
};
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),mycom());
        
        int n = words.size();
        vector<int>dp(n,1);

        for(int i=0;i<n;i++){

            for(int prev=0;prev<i;prev++){

                if( dp[prev]+1 > dp[i] &&match(words[prev],words[i]) ){
                      
                      dp[i] = dp[prev] + 1;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};