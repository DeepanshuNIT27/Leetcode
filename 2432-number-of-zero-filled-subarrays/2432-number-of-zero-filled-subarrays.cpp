class Solution {
public:
   vector<long long> v;
Solution(){
 v.resize(1e5+1, 0);
 v[1]= 1;
 v[2] = 3;
 for(int i=3;i<=1e5;i++){
    v[i] = i + v[i-1];
 }

}
    long long zeroFilledSubarray(vector<int>& nums) {
        int count = 0;
        vector<long long>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            else{
                ans.push_back(count);
                count = 0;
            }
        }
        ans.push_back(count);
        long long sum = 0LL;
        for(auto i:ans){
            sum += v[i];
        }
        return sum;
    }
};