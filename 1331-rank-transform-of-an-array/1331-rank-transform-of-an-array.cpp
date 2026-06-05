class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);

        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>>pq;

        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }

        int count = 1;
        int prev =  INT_MAX;

        while(!pq.empty()){
            
            auto temp = pq.top();
            pq.pop();

            if(temp.first != prev){
                ans[temp.second] = count;
                prev = temp.first;
                count++;
            }
            else{
                ans[temp.second] = count - 1;
            }
        }
        return ans;
    }
};