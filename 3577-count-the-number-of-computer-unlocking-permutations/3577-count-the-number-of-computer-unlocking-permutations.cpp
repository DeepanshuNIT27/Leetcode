class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int mod = 1e9+7;
        long long ans = 1LL;
        for(int i=1;i<complexity.size();i++){
            if(complexity[0]>=complexity[i]) return 0;
            ans = (ans *i)%mod;
        }
        return ans;
    }
};