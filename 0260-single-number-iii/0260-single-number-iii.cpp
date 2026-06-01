class Solution {
public:
// OPTIMAL APPROACH BITWISE LOGIC 
// WE WILL USE THE PARTITIONING USING XOR
    vector<int> singleNumber(vector<int>& nums) {
       
       long long xr = 0;
       int ans1 = 0;
       int ans2 = 0;
       for(auto&it:nums) xr = xr^ it;

       long long  rightMostIndex =  xr & (-xr);

       for(auto&it : nums){
           
           if(it & rightMostIndex){
              ans1 = ans1 ^ it;
           }
           else {
             ans2 = ans2 ^ it;
           }
       }
       return {ans1,ans2};
        
    }
};