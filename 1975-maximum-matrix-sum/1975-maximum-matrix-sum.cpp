class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum  = 0LL;
        int noOfNeg = 0;
        int mini = INT_MAX;
        for(auto&row:matrix){
            for(auto &temp:row){
                if(temp<0) noOfNeg++;
                sum += abs(temp);
                mini = min(mini,abs(temp));
            }
        }
        long long ans = noOfNeg%2==0 ? sum : sum - 2*mini ;
        return ans;
    }
};