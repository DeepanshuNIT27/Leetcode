class DisjoinSet{
    vector<int>rank,parent;
    
    public: 
     DisjoinSet(int n ){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int findUpar(int node){
        if(node == parent[node]){
            return node;
        }
        else return parent[node] = findUpar(parent[node]);
    }
    
    void unionByRank(int u , int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        
        if(ulp_u == ulp_v) return ;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
  //  DSU
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        DisjoinSet ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1){
                  ds.unionByRank(i,j);
                }
            }
        }
        int count = 0;
        for(int i=0;i<V;i++){
            if(ds.findUpar(i)==i) count++;
        }
        return count;
    }
};