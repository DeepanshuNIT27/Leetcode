class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
          
          vector<vector<int>>ans;
          int  s = newInterval[0];
          int  e = newInterval[1];

          int n = intervals.size();
          bool placed = false;

          for(int i=0;i<n;i++){

            if(intervals[i][1] < s ){
                ans.push_back(intervals[i]);
            }

            else if(intervals[i][0] > e){

                if(!placed){
                    ans.push_back({s,e});
                    placed = true;
                }
                ans.push_back(intervals[i]);
            }

            else{
                s = min(s,intervals[i][0]);
                e = max(e,intervals[i][1]);
            }
          }
          if(!placed){
            ans.push_back({s,e});
          }
          return ans;
    }
};