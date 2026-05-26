class Solution {
public:
//THIS IS A METHOD 1 CALLED SUFFIX MAX AND PREFIX MAX
// TIME AND SPACE COMPLEXITY WILL BE O(N);
    int trap(vector<int>& height) {
        
        int  n = height.size();
        vector<int>premax(n,0);
        vector<int>suffmax(n,0);
        premax[0] = height[0];

        //Prefix maxima 
        for(int i=1;i<n;i++){
          premax[i] = max(premax[i-1],height[i]);
        }

        //Suffix maxima 
        suffmax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
         suffmax[i] = max(suffmax[i+1],height[i]);
        }

        // calculation for water stored 
        int ans = 0;
        for(int i=0;i<n;i++){

            int waterlimit = min(premax[i],suffmax[i]);

            ans += waterlimit - height[i];
        }
        return ans;
    }
};