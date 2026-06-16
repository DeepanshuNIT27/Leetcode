class Solution {
public:
struct comp {
            
        bool operator()(vector<int>&a , vector<int>&b) const {

          if(a[1] == b[1]) {
              return a[0] < b[0];
          }
          return a[1]<b[1];
        }
};
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),comp());
        int n = intervals.size();
        int prev = -1e9 ;
        int cnt = 0;

        for(int i=0;i<n;i++){

            if(intervals[i][0] >= prev){
                 prev = intervals[i][1];
                 
            }
            else{
                cnt++;
            }
           
        }
return cnt;
    }
};