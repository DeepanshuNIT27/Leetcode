#include <vector>
using namespace std;

class UnionFind {
public:
    vector<int> parent;
    
    UnionFind(int n) {
        parent.resize(n + 1);  // As nodes are 1-indexed
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            parent[rootX] = rootY;  // Union the sets
            return true;
        }
        return false;  // If already in the same set, return false
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (!uf.unionSets(u, v)) {  // If u and v are already connected, return this edge
                return edge;
            }
        }
        return {};  // In case no redundant connection is found
    }
};
