class Solution {
public:
    bool canBeValid(string s, string locked) {
        int open = 0, close = 0, cnt = 0;
        int n = s.size();

        if (n % 2 != 0)
            return false;

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0')
                cnt++;
            else if (s[i] == '(')
                open++;
            else
                close++;
            if (close > open + cnt)
                return false;
        }

        open = 0;
        close = 0;
        cnt = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0')
                cnt++;
            else if (s[i] == '(')
                open++;
            else
                close++;

            if (open > close + cnt)
                return false;
        }

        return true;
    }
};