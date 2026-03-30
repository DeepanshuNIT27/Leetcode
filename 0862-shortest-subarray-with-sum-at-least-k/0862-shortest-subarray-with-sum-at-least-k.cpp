class Solution {
public:
// O(nlogn) complexity soln using deque
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
       set<pair<long long, int>> st; 
        vector<long long>prefixSum(n+1,0);
        for(int i=0;i<n;i++){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        int result = n+1;
        for(int i=0;i<=n;i++){
         
        while (!st.empty()) {
                auto it = st.begin();
                if (prefixSum[i] - it->first >= k) {
                    result = min(result, i - it->second);
                    st.erase(it);
                } else break;
            }

      
        st.insert({prefixSum[i], i});
    }

    return result == n+1 ? -1 : result;
}
};