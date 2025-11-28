class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
       long long ans = 0LL; 
        long long sum = 0LL;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
             ans = ans*10 + (s[i]-'0');
             sum += s[i]-'0';
            }
        }
       return 1LL*sum*ans;
        
    }
};