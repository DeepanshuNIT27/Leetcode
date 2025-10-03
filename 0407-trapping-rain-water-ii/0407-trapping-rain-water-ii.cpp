#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Add all border cells to the priority queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        
        // Directions for the 4 neighbors (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int trappedWater = 0;
        
        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top();
            minHeap.pop();
            int x = cell.first;
            int y = cell.second;
            
            // Check all 4 neighbors
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                
                // Ensure the neighbor is within bounds and not visited
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    // If the neighbor's height is lower than the current height, water can be trapped
                    trappedWater += max(0, height - heightMap[nx][ny]);
                    // Push the neighbor with the maximum height between current and the neighbor
                    minHeap.push({max(height, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }
        
        return trappedWater;
    }
};