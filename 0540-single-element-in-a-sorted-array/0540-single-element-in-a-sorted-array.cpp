class Solution {
public:
//OBSERVATION AGR SINGLE TIME AANE WALA ELEMENT NI AAYA RHEGA TB TK 
//SBKA FIRST OCC . EVEN INDEX PE HOGA .

// TIME COMPLEXITY - O(LOG N) TIME O(1) SPACE .
    int singleNonDuplicate(vector<int>& nums) {
        
        int n  = nums.size();
        int s = 0;
        int e = n-1;

        while(s<e){

            int mid  = s + (e-s)/2;

            if(mid&1) mid--;

            if(nums[mid] == nums[mid+1]) {
                s = mid + 2;
        }
        else {
            e = mid;
        }
        }
        return nums[s];
    }
};