class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq1, freq2;

        for (int fruit : basket1) freq1[fruit]++;
        for (int fruit : basket2) freq2[fruit]++;

        map<int, int> total;
        for (auto& [fruit, f] : freq1) total[fruit] += f;
        for (auto& [fruit, f] : freq2) total[fruit] += f;

        for (auto& [fruit, f] : total)
            if (f % 2 != 0) return -1; 

        vector<int> extra1, extra2;
        int minFruit = INT_MAX;

        for (auto& [fruit, f] : total) {
            int diff = freq1[fruit] - freq2[fruit];
            if (diff > 0) {
                for (int i = 0; i < diff / 2; ++i)
                    extra1.push_back(fruit);
            } else if (diff < 0) {
                for (int i = 0; i < (-diff) / 2; ++i)
                    extra2.push_back(fruit);
            }
            minFruit = min(minFruit, fruit);
        }

        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());

        long long cost = 0;
        for (int i = 0; i < extra1.size(); ++i) {
            cost += min({extra1[i], extra2[i], 2 * minFruit});
        }

        return cost;
    }
};