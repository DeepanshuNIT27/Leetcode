class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int count1 = 0;

        // Count the total number of 1's in the string
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count1++;
            }
        }

        int maxScore = 0;
        int leftScore = 0;  // Count of '0's in the left part

        // Iterate through the string to consider each possible split point
        for (int i = 0; i < n - 1; i++) {  // We split at position i (i < n-1)
            if (s[i] == '0') {
                leftScore++;  // Increment leftScore for '0' in the left part
            } else {
                count1--;  // Decrement count1 for '1' in the right part
            }

            // Calculate the score for the current split point
            int currentScore = leftScore + count1;
            maxScore = max(maxScore, currentScore);  // Update maxScore
        }

        return maxScore;
    }
};
