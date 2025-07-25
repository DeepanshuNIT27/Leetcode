class Solution {
public:
    bool checkDivisibility(int n) {
        string s = to_string(n);
        long long sum = 0LL;
        long long product = 1LL;
        for(int i=0;i<s.size();i++){
          int d = s[i]-'0';
          sum += d;
          product *= d;
        }
        if(n%(sum+product)==0) return true;
        return false;
    }
};