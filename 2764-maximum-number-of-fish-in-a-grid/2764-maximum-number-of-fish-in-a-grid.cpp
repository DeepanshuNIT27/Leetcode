class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions for moving up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // visited array to track if a cell is visited
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // DFS function to explore connected cells
        function<int(int, int)> dfs = [&](int x, int y) {
            // Base case: out of bounds or already visited or no fish in the cell
            if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || grid[x][y] == 0) {
                return 0;
            }
            
            // Mark the current cell as visited
            visited[x][y] = true;
            
            // Initialize the total fish count starting from this cell
            int totalFish = grid[x][y];
            
            // Explore all four directions
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                totalFish += dfs(nx, ny);
            }
            
            return totalFish;
        };
        
        int maxFish = 0;
        
        // Traverse each cell in the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If the cell is unvisited and contains fish, perform DFS
                if (!visited[i][j] && grid[i][j] > 0) {
                    maxFish = max(maxFish, dfs(i, j));
                }
            }
        }
        
        return maxFish;
    }
};
