class Solution {
public:
 bool possible(long long m ,long long &k, vector<int>& candies){
    long long ans = 0LL;
    for(auto&it:candies){
        ans += it/m;
        if(ans>=k) return true;
    }
    return false;
 }
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1LL;
        long long high = 1e7;
        long long ans = 0LL;
        while(low<=high){
           long long mid = low + (high - low)/2;
           if(possible(mid,k,candies)) {
             ans = mid ;
             low = mid+1;
           }
           else  high = mid-1;
        }
        return (int)ans;
    }
};