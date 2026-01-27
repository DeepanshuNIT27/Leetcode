class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        int mini = INT_MAX;
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
          if(abs(arr[i+1]-arr[i])<mini) mini = abs(arr[i+1]-arr[i]);
        }
        for(int i=0;i<n-1;i++){
         vector<int>temp;
          if(abs(arr[i+1]-arr[i])==mini) {
            temp.push_back(arr[i]);
            temp.push_back(arr[i+1]);
            ans.push_back(temp);
          }
        }
        return ans;

    }
};