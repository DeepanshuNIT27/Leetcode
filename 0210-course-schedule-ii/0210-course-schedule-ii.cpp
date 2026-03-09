class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int>q;
        vector<int>indegree(numCourses,0);
        unordered_map<int,list<int>>Adj;
        for(auto temp:prerequisites){
            Adj[temp[1]].push_back(temp[0]);
            indegree[temp[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto nbr : Adj[front]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        if(ans.size()==numCourses) return ans;
        ans.clear();
        return ans;
    }
};