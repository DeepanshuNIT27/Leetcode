class Solution {
public:
     void countBridges(int src, int parent , vector<int>&tin , vector<int>&low , unordered_map<int,bool>&vis, int timer,vector<vector<int>>&ans, unordered_map<int,list<int>>&adj){
        timer++;
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        //nbr pe travel krte hai 
        for(auto nbr: adj[src]){
            //undirected graph hai nbr parent bhi ho skta hai 
            if(nbr == parent){
                continue;
            }
            else if(!vis[nbr]){
                //normal travel kro aate time bridge check kr lena
                countBridges(nbr,src,tin,low,vis,timer,ans,adj);
                // bridg check
                // ye maibhul jata hu
                 low[src] = min(low[src],low[nbr]);
                if(low[nbr]>tin[src]){
                    vector<int>temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);

                }
            }
            else{
                //already visited and not parent 
                // low time ko update kro if possible
                low[src] = min(low[src],low[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
   int timer = 0;
   int src = 0;
   int parent = -1;
   vector<int>tin(n);
   vector<int>low(n);
   unordered_map<int,bool>vis;
   vector<vector<int>>ans;
   unordered_map<int,list<int>>adj;
   for(auto i:connections){
     int u = i[0];
     int v = i[1];
     adj[u].push_back(v);
     adj[v].push_back(u);

   }
      countBridges(src,parent,tin,low,vis,timer,ans,adj);
        return ans;
    }
};