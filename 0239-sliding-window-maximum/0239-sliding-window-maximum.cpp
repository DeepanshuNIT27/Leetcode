class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        // 1. first window
        for(int i=0 ;i<k ;i++){
            int element = nums[i];
            while(!dq.empty() && nums[dq.back()] <element){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        //ans of 1st window
        int index = dq.front();
        int element = nums[index];
        ans.push_back(element);
        //2. remaining window
        for(int i =k ; i< nums.size();i++){
            //removal
            if(!dq.empty() && i-dq.front()>= k ){
                dq.pop_front();
            }
            //adding 
            int Element = nums[i];
             while(!dq.empty() && nums[dq.back()] <Element){
                dq.pop_back();
            }
            dq.push_back(i);
            // ans likho
            int index = dq.front();
        int Element1 = nums[index];
        ans.push_back(Element1);
        }
        return ans;
    }
};