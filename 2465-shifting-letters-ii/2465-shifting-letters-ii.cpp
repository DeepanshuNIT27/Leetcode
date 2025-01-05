class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        // Apply shifts using a difference array
        for (auto &shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2] == 0 ? -1 : 1;

            diff[start] += direction;
            diff[end + 1] -= direction;
        }

        // Accumulate the difference to calculate the net shifts
        int shiftValue = 0;
        for (int i = 0; i < n; ++i) {
            shiftValue += diff[i];
            int netShift = (shiftValue % 26 + 26) % 26; // Handle negative shifts
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }

        return s;
    }
};