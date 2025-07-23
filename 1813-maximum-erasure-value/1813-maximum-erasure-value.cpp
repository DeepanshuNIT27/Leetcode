class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int result = 0;
        int n = nums.size();
        unordered_set<int>st;
        while(j<n){
            //pahli bar mila
            if(!st.count(nums[j])){
                st.insert(nums[j]);
                sum += nums[j];
                result = max(sum,result);
                j++;
            }
            // dekh chuke hai
            else{
            while(i<j && st.count(nums[j])){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            }
        }
        return result;
    }
};
