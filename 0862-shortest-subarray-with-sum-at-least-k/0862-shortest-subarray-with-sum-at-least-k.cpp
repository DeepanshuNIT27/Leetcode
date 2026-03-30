class Solution {
public:
// O(n) complexity soln using deque
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        vector<long long>prefixSum(n+1,0);
        for(int i=0;i<n;i++){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        int result = n+1;
        for(int i=0;i<=n;i++){
         
         while(!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k){
               result = min(result , i-dq.front());
               dq.pop_front();
        }

        while(!dq.empty() && prefixSum[i]<=prefixSum[dq.back()]){
            dq.pop_back();
        }

        dq.push_back(i);
    }

    return result == n+1 ? -1 : result;
}
};