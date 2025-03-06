class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // USING MIN-HEAP
    //     priority_queue<int, vector<int> ,greater<int>>pq;
    //     for(int i=0;i<k ;i++){
    //         pq.push(nums[i]);
    //     }
    //     for(int i=k ;i< nums.size();i++){
    //         int element = nums[i];
    //         if(element > pq.top()){
    //             pq.pop();
    //             pq.push(element);
    //         }
    //     }
    //     return pq.top();
    // }
    //MAX-HEAP
    priority_queue<int>pq;
    for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
    }
    k = k-1;
    while(k){
        pq.pop();
        k--;
    }
    return pq.top();
    }
};