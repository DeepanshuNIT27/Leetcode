class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long n = grid[0].size();
        vector<long long>v(n);
        vector<long long>b(n);
        v[0] = grid[0][0];
        b[0] =grid[1][0];
        long long a = 0;
        long long z = 0;
        long long ans = 0;
        long long y = LLONG_MAX;
        for(long long i=1;i<n ;i++){
          v[i] =  v[i-1] +grid[0][i];
        }
        for(long long j=1 ;j< n;j++){
            b[j] = b[j-1] + grid[1][j];
        }
          for(int i=0 ;i<n ;i++){
            a = v[n-1] - v[i];
            z =  i==0 ? 0: b[i-1];
            ans = max(a,z);
            y = min(y,ans);
          }
        return y;
    }
};