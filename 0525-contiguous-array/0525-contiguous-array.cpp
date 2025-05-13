class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int sum = 0;
        int sub_array = 0;
        for(int i=0;i< nums.size();i++){
            if(nums[i] == 0){
                sum -= 1;
            }
            else{
                sum += 1;
            }
            if(sum == 0){
                if(sub_array < i+1){
                    sub_array = i+1;
                }
            }
            else if(mp.find(sum)!= mp.end()){
                if(sub_array < i-mp[sum]){
                    sub_array = i-mp[sum];
                }
            }
            else{
                mp[sum] = i ;
            }
        }
        return sub_array;
    }
};