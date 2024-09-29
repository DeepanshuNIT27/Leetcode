class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int e = n-1;
        int mid = s+(e-s)/2;
        while(s<=e){
            if(s==e){
                return nums[s];
            }
            int currentvalue =nums[mid];
            int leftvalue= -1; 
            if(mid-1>=0){
                leftvalue =nums[mid-1];
            }
            int rightvalue =-1;
            if( mid+1<n){
                rightvalue= nums[mid+1];
            }
            if(currentvalue!=leftvalue &&  currentvalue!=rightvalue){
                return currentvalue;
            }
            if(currentvalue==leftvalue && currentvalue != rightvalue){
                int firstpair = mid-1;
                if(firstpair&1){
                    e= mid-1;
                }
                else{
                    s= mid+1;
                }
            }
            if(currentvalue==rightvalue && currentvalue!=leftvalue){
                int firstpair= mid;
                if(firstpair&1){
                    e = mid-1;
                }
                else{
                    s= mid+1;
                }
            }
            mid = s+(e-s)/2;

        }
        return -1;
        
    }
};