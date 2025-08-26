class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        long long maxi = 0;
        long long  maxdim = 0;
        for(int i=0;i<n;i++){
        long long leg = dimensions[i][0];
        long long wid = dimensions[i][1];
         long long z = (leg*leg + wid*wid);
         if(z>maxdim){
            maxdim = z;
            maxi = leg*wid;
         }
         else if(z==maxdim){
          maxi =   max(maxi,leg*wid);
         }
        }
        return maxi;
    }
};