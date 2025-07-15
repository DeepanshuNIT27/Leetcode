class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.rbegin(),s.rend());
        int n1 = s[0]-'0';
        int m = s[1] -'0';
        return n1*m;
    }
};