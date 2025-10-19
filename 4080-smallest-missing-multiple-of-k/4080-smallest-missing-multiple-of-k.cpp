class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        for(int i=1;i<=100;i++){
            if(i%k==0 ){
                if(count(nums.begin(),nums.end(),i)==0)  return i;
            }
        }
        int d =  ceil(100.0/k) * k;
         if(d>100) return d;
         return d + k;
    }
};