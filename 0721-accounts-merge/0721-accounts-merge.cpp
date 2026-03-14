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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // DSU
        int n = accounts.size();
        DisjoinSet ds(n);
        //sare mail ko number assign kro usse dsu laga skenge agr vo mail
        //pahle se present hai to dsu merge lga do 
        unordered_map<string,int>mapMailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else {
                   ds.unionByRank(i, mapMailNode[mail]);
                }
            }
        }

        // jinka ultimate parent same hai unko combine krenge 
        vector<vector<string>>mergeMail(n);
        for(auto &it : mapMailNode){
            string mail = it.first;
            int node = ds.findUpar(it.second);
            mergeMail[node].push_back(mail);
        }

        // ab ans prepare kro
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(int j=0;j<mergeMail[i].size();j++){
              temp.push_back(mergeMail[i][j]);
            }
            ans.push_back(temp);
        }


       return ans; 
    }
};