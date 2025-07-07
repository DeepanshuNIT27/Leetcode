class Solution {
public:
void dfs(int node ,unordered_map<int,vector<int>>&mp,unordered_map<int,bool>&visited, vector<int>&ans){
       visited[node] = true;
       ans.push_back(node);
       for(auto temp:mp[node]){
            if(!visited[temp]){
                dfs(temp,mp,visited,ans);
            }
        }
       }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<connections.size();i++){
            auto temp = connections[i];
           int u = temp[0];
           int v = temp[1];
           mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int>ans;
        unordered_map<int,bool>visited;
        vector<vector<int>>final;
        for(int i=1;i<=c;i++){
            if(!visited[i]){
                dfs(i,mp,visited,ans);
                sort(ans.begin(),ans.end());
                final.push_back(ans);
                ans.clear();
            }
        }
        //final logic
        unordered_map<int,int>track;
        unordered_map<int,set<int>>active;
       for(int i=0;i<final.size();i++){
         auto temp = final[i] ;
         for(auto j:temp){
            track[j] = i;
            active[i].insert(j);
         }
       }
       vector<int>anshai;
       for(int i=0;i<queries.size();i++){
        auto p = queries[i];
        int l = p[0];
        int f = p[1];
        int id = track[f];
        if(l==2){
           active[id].erase(f);//deactivate;
        }
        else{
           if(active[id].count(f)){
            anshai.push_back(f);
           }
           else if(!active[id].empty()){
            anshai.push_back(*active[id].begin());
           }
           else{
            anshai.push_back(-1);
           }
        }
       }
        return anshai;
    }
};