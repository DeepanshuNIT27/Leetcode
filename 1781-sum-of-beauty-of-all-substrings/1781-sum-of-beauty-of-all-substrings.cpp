class Solution {
public:
    int beautySum(string s) {
        
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
           vector<int>v(26,0);
           int maxi = 0;
            for(int j=i;j<n;j++){
               
               v[s[j]-'a']++;
               maxi = max(maxi,v[s[j]-'a']);
               int mini = maxi;
               for(int k=0;k<26;k++){
                  if(v[k]>0){
                    mini = min(mini,v[k]);
                  }
               }
                ans += maxi - mini;
            }
        }
        return ans;
    }
};