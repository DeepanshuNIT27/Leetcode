class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);
        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        vector<string> result;
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }
            bool valid = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result.push_back(word);
            }
        }

        return result;
    }
};