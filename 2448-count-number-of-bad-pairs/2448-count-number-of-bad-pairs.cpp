class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<long long, long long> countMap;
        long long goodPairs = 0;

        // Iterate over each element to calculate the difference nums[i] - i
        for (int i = 0; i < n; i++) {
            long long diff = nums[i] - i;
            goodPairs += countMap[diff];  // If the difference has appeared before, it's a good pair
            countMap[diff]++;  // Store the count of this difference
        }

        // Total possible pairs - good pairs = bad pairs
        long long totalPairs = n * (n - 1) / 2;
        long long badPairs = totalPairs - goodPairs;
        return badPairs;
    }
};
