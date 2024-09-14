class Solution {
public:

   int missingNumber( vector<int>&nums){
    sort(nums.begin(), nums.end());
    int  ansIndex = -1;
    int n = nums.size();
    int s = 0;
    int e = n-1;
    int mid =  s+( e-s)/2;
    while(s<=e){

        int number = nums[mid];
        int index = mid;
        int difference = number - index;
        if( difference ==0){
            s= mid+1;
        }
        else if ( difference ==1) {
            ansIndex= index;
            e = mid -1;
        }
        mid  = s +(e-s)/2;
    }
        if(ansIndex==-1){
            return n;
        }
       
    
     return ansIndex;
   }
      };

