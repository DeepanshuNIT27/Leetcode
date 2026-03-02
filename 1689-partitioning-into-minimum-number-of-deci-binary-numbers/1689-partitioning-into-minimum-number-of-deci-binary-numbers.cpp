class Solution {
public:
    int minPartitions(string s) {
        char maxi = *max_element(s.begin(),s.end());
        return maxi - '0';
    }
};