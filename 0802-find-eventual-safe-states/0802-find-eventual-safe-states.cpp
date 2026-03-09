class Solution {
public:
//Using the Topo sort
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        unordered_map<int,list<int>>ReAdj;
        queue<int>q;
       vector<int>indegree(V,0);
       vector<int>ans;
       for(int i=0;i<V;i++){
        auto temp = graph[i];
        for(int j=0;j<temp.size();j++){
            ReAdj[temp[j]].push_back(i);
            indegree[i]++;
        }
       }
       for(int i=0;i<V;i++) if(indegree[i]==0) q.push(i);
       while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto nbr:ReAdj[front]){
            indegree[nbr]--;
            if(indegree[nbr]==0) q.push(nbr);
        }
      
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};