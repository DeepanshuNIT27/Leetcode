class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = strs[0];  // Initialize with the first string
        
        for (int i = 1; i < n; i++) {  // Start from the second string
            int j = 0;
            // Compare characters of ans and strs[i] while they match
            while (j < ans.size() && j < strs[i].size() && ans[j] == strs[i][j]) {
                j++;
            }
            ans = ans.substr(0, j);  // Update ans to the common prefix found
            if (ans == "") return "";  // If no common prefix, return empty string
        }
        
        return ans;
    }
};
