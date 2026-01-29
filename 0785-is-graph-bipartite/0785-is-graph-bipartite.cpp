class Solution {
public:
  //BFS
  bool bfs(int i ,vector<vector<int>>& graph, vector<int>&colour  ){
     queue<int>q;
     q.push(i);
     colour[i] = 0;
      while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto&nbr:graph[front]){
                if(colour[nbr]==-1){
                    colour[nbr] = !colour[front];
                    q.push(nbr);
                }
                else if(colour[nbr]==colour[front]) return false;
            }
        }
        return true;
  }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colour(n,-1);
        for(int i=0;i<n;i++){
          if(colour[i]==-1){
            if(!bfs(i,graph,colour)) return false;
          }
        }
       
        return true;
    }
};