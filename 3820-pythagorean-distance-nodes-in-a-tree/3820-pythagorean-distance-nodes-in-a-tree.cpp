class Solution {
public:
bool pytha(long long a, long long b, long long c)
{
    int maxi = max(c,max(a,b));
    if(maxi==a && a*a == b*b + c*c) return true;
    else if(maxi == b && b*b == a*a + c*c) return true;
    else if(maxi ==c && c*c == a*a +b*b ) return true;
    return false;
}
void bfs( vector<bool>visited, unordered_map<int,vector<int>>Adj, int start, vector<pair<int,int>>&v){
    visited[start] = true;
    queue<pair<int,int>>q;
    q.push({start,0});

    while(!q.empty()){
        auto front = q.front();
        q.pop();
        v.push_back(front);
        for(auto nbr : Adj[front.first]){
            if(!visited[nbr]){
                visited[nbr] = true;
                q.push({nbr,front.second+1});
            }
        }
    }
}
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {

        //Adjacency list
       unordered_map<int,vector<int>>Adj;
       for(int i=0;i<edges.size();i++){
         int v = edges[i][0];
         int u = edges[i][1];
        Adj[v].push_back(u);
        Adj[u].push_back(v);  
       }
       vector<pair<int,int>>a;
       vector<pair<int,int>>b;
       vector<pair<int,int>>c;
       vector<bool>visited(n,false);
       bfs(visited,Adj,x,a);
       bfs(visited,Adj,y,b);
       bfs(visited,Adj,z,c);
       sort(a.begin(),a.end());
       sort(b.begin(),b.end());
       sort(c.begin(),c.end());
       int count = 0;
       for(int i=0;i<a.size();i++){
         long long x = a[i].second;
          long long y = b[i].second;
          long long z = c[i].second;
          if(pytha(x,y,z)) count++;
       }
return count;
       
    }
};