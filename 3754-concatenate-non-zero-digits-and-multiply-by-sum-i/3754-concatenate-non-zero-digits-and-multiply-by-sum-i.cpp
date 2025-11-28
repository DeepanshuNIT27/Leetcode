class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string ans = "";
        long long sum = 0LL;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                ans.push_back(s[i]);
                sum += s[i]-'0';
            }
        }
        long long z = 0LL;
     if(ans.size()!=0)   z = stoll(ans);
        cout<<z<<" ";
        return 1LL*z*sum;
        
    }
};